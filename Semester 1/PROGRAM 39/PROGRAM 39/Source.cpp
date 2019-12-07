#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outfile("example.txt");

	// Check if the file was opened.
	if (!outfile.is_open())
	{
		cerr << "File could not be opened!";
		std::exit(1);
	}

	// To reach here the file must be open.
	// Write to the open file.
	outfile << "This is a line.\n";
	outfile << "This is another line.\n";

	// Close the file.
	outfile.close();

	return 0;
}
