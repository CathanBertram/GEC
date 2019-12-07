#include <iostream>

using namespace std;

void inputDetails(int* n1, int* n2);

void outputDetails(int* num1, int* num2, int* pNum);

int main()
{
	int num1, num2;
	int* pNum=&num1;
	inputDetails(&num1, &num2);
	outputDetails(&num1, &num2, pNum);

	pNum = nullptr;

	cin.get();
	return 0;
}

void inputDetails(int* n1, int* n2)
{
	cout << "Enter A Value" << endl;
	cin >> *n1;
	cout << "Enter A Value" << endl;
	cin >> *n2;
}

void outputDetails(int* num1, int* num2, int* pNum)
{
	cout << "Num1: " << *num1 << endl;
	cout << "Num1 Address: " << &num1 << endl;
	cout << "Num2: " << *num2 << endl;
	cout << "Num2 Address: " << &num2 << endl;
	cout << "pNum Value: " << pNum << endl;
	cout << "Dereferenced pNum Value: " << *pNum << endl;
	cout << "pNum Address: " << &pNum << endl;
}
