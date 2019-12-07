#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string lineOfText;
	ifstream infile("example.txt");

	// Check if the file was opened.
	if (infile.is_open())
	{
		// Loop through the entire file and output each line to the console.
		while (getline(infile, lineOfText))
		{
			cout << lineOfText << endl;
		}

		// Close the file.
		infile.close();
	}
	else
	{
		// File did not open. Inform the user.
		cout << "Unable to open file";
	}

	cin.get();
	return 0;
}
