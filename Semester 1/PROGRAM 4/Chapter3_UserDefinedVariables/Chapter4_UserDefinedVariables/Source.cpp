#include <iostream>

using namespace std;

int main() {

	typedef int currentDate;

	enum month {
		January = 1,
		Ferbruary,
		March,
		April,
		May,
		June,
		July,
		August,
		Spetember,
		October,
		November,
		December
	};

	currentDate date = 15;
	month currentMonth = April;
	

	cout << "the date is " << date << "/" << currentMonth << endl;
	cin.get();
	return 0;


}