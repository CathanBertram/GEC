#include <iostream>;

using namespace std;

int main() {
	int n;
	cout << "Please Enter A Value Between 1 And 10" << endl;
	cin >> n;

	for (n; n >= 0; n--) {
		cout <<  string(n-1+n,'*') << endl;
	}

	
	
	cin.get();
	return 0;
}