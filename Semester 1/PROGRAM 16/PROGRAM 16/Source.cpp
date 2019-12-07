#include <iostream>

using namespace std;

int smallerNumber(int a, int b);

int int3;

int test;
int main() {
	int int1;
	int int2;

	cout << "Enter Integer 1" << endl;
	cin >> int1;
	cout << "Enter Integer 2" << endl;
	cin >> int2;

	int3 = smallerNumber(int1, int2);


	if (int3 == -9999) {
		cout << "Both Values You Entered Were "<<int1 << endl;
	}
	else {
		cout << "The Smallest Number Is " << int3 << endl;
	}


	return 0;
}
int smallerNumber(int a, int b) {
	if (a < b) {
		return a;
	}
	else if (b < a) {
		return b;
	}
	else if(a == b) {
		return -9999;
	}
}