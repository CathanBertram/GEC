#include <iostream>
#include <string>

using namespace std;

int main()
{
	int input = 0;
	int output = 0;
	int r;
	int count;
	while (input != -1)
	{
		input = 0;
		output = 0;
		r = 0;
		cout << "Input An Integer With At Least 2 Digits" << endl;
		cin >> input;
		if (input == -1)
		{
			break;
		}
		count = to_string(input).length();
		if (count != 1)
		{
			while (input != 0)
			{
				r = input % 10;
				output = output * 10 + r;
				input /= 10;
			}
			cout << "The Reversed Number Is: " << output << endl;		
		}
		if (count ==1)
		{
			cout << "This Number Is Invalid" << endl;
		}
	} 
	cin.get();
	return 0;
}