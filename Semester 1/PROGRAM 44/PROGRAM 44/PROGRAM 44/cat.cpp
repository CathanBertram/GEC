#include "Cat.h"

Cat::Cat(int initialAge)
{
	itsAge = initialAge;
}

Cat::~Cat()
{
}

int Cat::GetAge()
{
	return itsAge;
}

void Cat::SetAge(int age)
{
	itsAge = age;
}
