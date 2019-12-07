#include <iostream>

using namespace std;

int main()
{
	int num;
	cout << "Input a Number" << endl;
	cin >> num;
	int& rNum = num;
	cout << num << endl;
	rNum += 25;
	cout << num << endl;
	cout << "Input a Number" << endl;
	cin >> num;
	cout << num << endl;
	rNum -= 25;
	cout << num << endl;

	cin.get();
	return 0;
}