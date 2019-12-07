#include <iostream>

using namespace std;

#include <iomanip>

using std::setw;

int main() {
	int myNumbers[10];

	//Initialize Elements Of The Array
	for (int i = 0; i < 10; i++)
		myNumbers[i] = i;
	//output titles
	cout << "Array Element" << setw(10) << "Stored Value" << endl;

	//output each array elements value
	for (int i = 0; i < 10; i++)
	{
		cout << setw(5) << i << setw(15) << myNumbers[i] << endl;//changed setw(20) to setw(15) to make it more central
	}
	return 0;
}