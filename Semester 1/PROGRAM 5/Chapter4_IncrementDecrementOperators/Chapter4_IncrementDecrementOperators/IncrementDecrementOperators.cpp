#include <iostream>

using namespace std;

int main() {
	//initialise num to 1
	int num = 1;
	cout << "num=" << num << endl;
	cout << "increment operator before num=" << ++num << endl;
	cout << "num after=" << num << endl;
	
	//reset num to 1`
	num = 1;

	cout << "num=" << num << endl;
	cout << "increment operator after num=" <<num++ << endl;
	cout << "num after=" << num << endl;

	//reset num to 1`
	num = 1;

	cout << "num=" << num << endl;
	cout << "decrement operator before num=" << --num << endl;
	cout << "num after=" << num << endl;

	//reset num to 1`
	num = 1;

	cout << "num=" << num << endl;
	cout << "decrement operator after num=" << --num << endl;
	cout << "num after=" << num << endl;

	cin.get();
	return 0;
}