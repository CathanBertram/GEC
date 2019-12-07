#include <iostream>
#include <string>

using namespace std;

string convertToString(char* a) {
	string s (a);
	return s;
}

int main() {
	string sentence = "0";
	int spaceCount = 0;
	cout << "Please Enter A Sentence In Lower Case" << endl;
	getline(cin, sentence);
	cout << "**********************" << endl <<  sentence << endl;
	for (int i = 0; i < sentence.length(); i++)
	{
		int position = -1;
		position = sentence.find("e");
		if (position !=-1)
		{
			sentence.replace(position, 1, "X");
		}
	}
	cout << sentence << endl;
}