#include <iostream>
#include <string>

using namespace std;

int main()
{
	string testString = "Do you know who loves C++, XX does!";
	string name1;
	string name2;
	int position;
	int length1;
	int length2;
	cout << "Enter Your Name" << endl;
	getline(cin, name1);

	cout << testString << endl;
	position = testString.find("XX");
	testString.replace(position, 2, name1);
	cout << testString << endl;
	cout << "Enter Another Name Longer Than The First Name" << endl;
	getline(cin, name2);
	while (name1.length() > name2.length())
	{
		cout << "The Second Name Must Be Longer Than The First" << endl;
		getline(cin, name2);
	}
	testString.replace(position, name1.length(), name2);
	cout << testString;

	cin.get();
	return 0;
}