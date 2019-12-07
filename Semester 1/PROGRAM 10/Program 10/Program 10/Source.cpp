#include <iostream>

using namespace std;

int main() {
	int haribos = 40;
	int students = 14;

	int share = 40 / 14;
	int remaining = 40 % 14;

	cout << "each student gets " << share << " bags of haribos, and there are " << remaining << " bags of haribos left over" << endl;
	cin.get();
	return 0;

}