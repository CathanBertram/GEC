#include <iostream>
#include <string>

using namespace std;

struct userInfo
{
	string name;
	int age;
	string number;
	void PrintDetails(string name, int age, string number);
};

int main()
{
	userInfo person;


	cout << "Please Enter Your Name" << endl;
	getline(cin, person.name);
	cout << "Please Enter Your Age In Years" << endl;
	cin >> person.age;
	cout << "Please Enter Your Phone Number" << endl;
	cin >> person.number;
	person.PrintDetails(person.name, person.age, person.number);

	cin.get();
	return 0;
}

void userInfo::PrintDetails(string name, int age, string number)
{
	cout << "Your Name Is " << name << endl;
	cout << "You Are " << age << " Years Old" << endl;
	cout << "Your Phone Number Is " << number << endl;
}
