#include "Luffy.h"

REFLECT(Luffy);

Luffy::Luffy()
{
	std::cout << "Luffy()" << std::endl;
}


Luffy::~Luffy()
{
	std::cout << "~Luffy()" << std::endl;
}

void Luffy::show()
{
	std::cout << "Hello, I'm Luffy" << std::endl;
}