// refs: https://blog.csdn.net/q1007729991/article/details/56012253

#include <iostream>
#include <string>
#include "Person.h"
#include "Reflector.h"


int main()
{
    std::cout << "Hello World!\n";
    Person* allen = getNewInstance<Person>("Allen");
    Person* luffy = getNewInstance<Person>("Luffy");
    allen->show();
    luffy->show();
    delete allen;
    delete luffy;
    return 0;
}
