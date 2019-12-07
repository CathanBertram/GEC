#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	int playerLife = 100;
	int i = 1;
	int damage;
	
	for (int counter = 10; counter != 0; counter--)	
	{
		if (playerLife >= 1) {
			cout << "Question " << i << ": How Much Should We Decrease The Health By?"<< endl;
			cin >> damage;
			playerLife = playerLife - damage;
			cout << "The Player Now Has  " << playerLife << " Health" << endl;
			if (playerLife < 1)
			{
				cout << "Early Exit" << endl;
				Sleep(10);
				exit;
			}
		}
		i++;
	}
	if (playerLife >0)
	{
		cout << "All 10 Questions Have Been Asked And The Player Still Has Life Remaining" << endl;
	}
	
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
	return 0;
}