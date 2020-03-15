#include "Allen.h"

REFLECT(Allen);

Allen::Allen()
{
	std::cout << "Allen()" << std::endl;
}


Allen::~Allen()
{
	std::cout << "~Allen()" << std::endl;
}

void Allen::show()
{
	std::cout << "Hello, I'm Allen" << std::endl;
}