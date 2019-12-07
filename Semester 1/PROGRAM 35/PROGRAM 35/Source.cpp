#include <iostream>
#include <string>

using namespace std;

void comma2blank(char* textToChange)
{
	char blank = ' ';
	*textToChange = blank;
}

int main()
{
	char sentence[100] = { 0 };
	cout << "Enter Some Text" << endl;
	cin.getline(sentence, 100);

	for (int i = 0; i < 100; i++)
	{
		if (sentence[i]==',')
		{
			comma2blank(&sentence[i]);
		}
		cout << sentence[i];
	}
	cin.get();
	return 0;

}