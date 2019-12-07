#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
	int option =0;
	string score;

	ifstream infile("scores.txt");
	if (!infile)
	{
		cout << "File Could Not Be Found - Making New File" << endl;
		infile.close();
		ofstream outfile("scores.txt", ios::out);
		for (int i = 0; i < 10; i++)
		{
			outfile << "0 test \n";
		}
		outfile.close();
	}
	while (option != 3)
	{
		cout << "1. Enter a score" << endl << "2. Display scores" << endl << "3. Exit" << endl;
		cin >> option;
		if (option == 1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Enter a Score and a Name" << endl;
			getline(cin, score);
			cout << score << endl;
			ofstream outfile("scores.txt", ios::in);
			ifstream infile("scores.txt");
			string check;
			int a;
			int b;
			istringstream(score) >> a;
			streampos pos = outfile.tellp();
			while (getline(infile, check))
			{
				istringstream (check) >> b;
				cout << a << "    " << b << endl;
				if (a>=b)
				{
					outfile.seekp(pos);
					outfile << score << endl;
					break;
				}
				streampos pos = outfile.tellp();
			}
			infile.close();	
			outfile.close();
		}
		else if (option == 2)
		{
			string scores;
			ifstream infile("scores.txt");
			if (infile.is_open())
			{
				while (getline(infile, scores))
				{
					cout << scores << endl;
				}
				infile.close();
			}
		}
		else if (option == 3)
		{
			cout << "Thanks For Using Our Score System!" << endl;
			infile.close();
			break;
		}
		else
		{
			cout << "Option Is Invalid" << endl;
		}
	}
	


	cin.get();
	return 0;
}