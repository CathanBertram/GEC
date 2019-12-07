#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int main() {
	int n;
	int counter = 0;
	char restart = 'y';
	using namespace std::this_thread; // sleep_for, sleep_until 
	using namespace std::chrono_literals; // ns, us, ms, s, h, etc. 
	using std::chrono::system_clock;
	do
	{
		cout << "Please Enter A Value Between 1 And 10" << endl;
		cin >> n;
		if (n <= 10, n > 0)
		{
			for (n; n >= 1; n--) {
				counter++;
				cout << string(counter, '*') << endl;
			}
			counter = 0;
			cout << "Would You Like To Try Again Y/N" << endl;
			cin >> restart;
		}
		else
		{
			cout << "The Value Must Be Between 0 And 10" << endl;
			cout << "Would You Like To Try Again Y/N" << endl;
			cin >> restart;
		}
		if (restart != 'y') {
			cout << "You Must Enter A 'Y' Or An 'N'" << endl;
			cout << "Would You Like To Try Again Y/N" << endl;
			cin >> restart;
		}
		else if (restart != 'n') {
			cout << "You Must Enter A 'Y' Or An 'N'" << endl;
			cout << "Would You Like To Try Again Y/N" << endl;
			cin >> restart;
		}
	} while (restart != 'n');
	cout << "Goodbye" << endl;
	sleep_for(10ns);
	sleep_until(system_clock::now() + 2s);
	cin.get();
	return 0;
}