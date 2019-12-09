#include "Cat.h"
#include <iostream>

using namespace::std;

int main()
{
	// Create on the stack – Has parameters so the brackets are required along with the starting value.
	Cat button(5);

	// Create on the heap.
	Cat* pDaisy = new Cat(10);

	cout << "Button is " << button.GetAge() << " years old." << endl;
	cout << "Daisy is " << pDaisy->GetAge() << " years old." << endl;

	cin.get();

	delete pDaisy;
	return 0;
}
