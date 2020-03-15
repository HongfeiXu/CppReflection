#pragma once

#include <string>
#include <iostream>
#include <map>


// ������Ҫʵ�ַ��������Ҫ�̳���
class ReflectObject {
public:
	virtual ~ReflectObject(){}
};


// ���󹤳������࣬�������ɶ���ʵ��
class ObjectFactory {
public:
	ObjectFactory() { std::cout << "ObjectFactory()" << std::endl; }
	virtual ~ObjectFactory() { std::cout << "~ObjectFactory()" << std::endl; }
	virtual ReflectObject* newInstance() = 0;
};


// ���������������������������󹤳�����ӳ���ϵ
class Reflector
{
public:
	Reflector();
	~Reflector();
	void registerFactory(const std::string& className, ObjectFactory* of);
	ReflectObject* getNewInstance(const std::string& className);
private:
	std::map<std::string, ObjectFactory*> objectFactories;
};


// ��ȡ������ʵ����ȫ��Ψһ
Reflector& reflector();


// Ҫ��������࣬��Ҫ�����Ӧ�� cpp �ļ��н��з�������
#define REFLECT(name)\
class ObjectFactory_##name : public ObjectFactory{\
public:\
	ObjectFactory_##name(){ std::cout << "ObjectFactory_" << #name << "()" << std::endl; }\
	virtual ~ObjectFactory_##name(){ std::cout << "~ObjectFactory_" << #name << "()" << std::endl; }\
	ReflectObject* newInstance() {\
		return new name(); \
	}\
}; \
class Register_##name{\
public:\
	Register_##name(){\
		reflector().registerFactory(#name, new ObjectFactory_##name()); \
	}\
};\
Register_##name register_##name;

// ����������ȡ����ʵ��
template<typename T>
T* getNewInstance(const std::string& className) {
	return dynamic_cast<T*>(reflector().getNewInstance(className));
}

// ˵����������������REFLECT(Allen) �ȼ���������������

/*
// ���� 1 ������Allen�Ĺ�����
class ObjectFactory_Allen : public ObjectFactory {
	ReflectObject* newInstance() {
		return new Allen();
	};
}

// ���� 2 ����Allen����ʵ�����󣬲�ע��ൽ��������
reflector().registerFactory("Allen", new ObjectFactory_Allen());
*/