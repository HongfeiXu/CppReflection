#pragma once
#include "Person.h"

Person::Person()
{
	std::cout << "Person()" << std::endl;
}

Person::~Person()
{
	std::cout << "~Person()" << std::endl;
}

void Person::show()
{
	std::cout << "Hello, I'm a person" << std::endl;
}