#include <iostream>

using namespace std;

int main() {


	int input;
	
	do
	{

	cout << "Please choose an option : 1. Sunny 2. Cloudy 3.  Raining 4. Exit" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "Don't Forget Your Sunscreen" << endl;
		break;
	case 2:
		cout << "Where'd The Sun Go" << endl;
		break;
	case 3:
		cout << "Don't Forget Your Umbrella" << endl;
		break;
	case 4:
		cout << "See Ya Later " << endl;
		break;
	}
	} while (input !=4);
	cin.ignore();

	cin.get();
	return 0;
}
