#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	streampos begin, end;

	// Open the file.
	ifstream inFile("example.txt", ios::binary);

	if (!inFile)
	{
		cerr << "File could not be opened!";
		std::exit(1);
	}

	// Get the current position in the file.
	begin = inFile.tellg();

	// Reposition the file pointer to the end of the file.
	inFile.seekg(0, ios::end);

	// Get the current position in the file.
	end = inFile.tellg();

	// Close the file.
	inFile.close();

	cout << "size is: " << (end - begin) << " bytes.\n";

	cin.get();
	return 0;
}
