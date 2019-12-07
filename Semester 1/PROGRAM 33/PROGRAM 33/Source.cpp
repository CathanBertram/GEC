#include <iostream>
using namespace std;

int main()
{
	// Create a normal int variable.
	int myNum = 5;

	// Create a int pointer variable and point it toward the variable just created.
	int* pPointerToMyNum = &myNum;

	// Output the values stored in each variable.
	cout << "myNum = "<< myNum << endl;
	cout << "pPointerToMyNum = "<< pPointerToMyNum << endl;

	// Notice that pPointerToMyNum does not output ‘5’. We need to dereference the pointer.
	cout << "* pPointerToMyNum = "<< *pPointerToMyNum << endl;

	// All variables have their own memory addresses. This is how they are stored.
	// The next two lines of code show the memory address of myInt and the address that  
	// pPointerToMyNum points to.
	cout << "& myNum = "<< &myNum << endl;
	cout << "pPointerToMyNum = "<< pPointerToMyNum << endl;

	// To complete the circle lets look at the memory address of pPointerToMyNum.
	cout << "& pPointerToMyNum = "<< &pPointerToMyNum << endl;

	// Pause for input.
	cin.get();

	return 0;
}
