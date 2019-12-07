#include <iostream>

using namespace std;

int main() {
	int input1;
	int input2;
	int output;
	int inputs=0;
	float mean;
	int input3;
	cout << "Enter a Whole Number Value" << endl;
	cin >> input1;
	inputs++;
	if (input1 == 0) {
		cout << "We Don't Take Zeros Here" << endl;
		cin.get();
		exit(1);
	}
	cout << "Enter Another Whole Number Value" << endl;
	cin >> input2;
	inputs++;
	if (input2 == 0) {
		cout << "We Don't Take Zeros Here" << endl;
		cin.get();
		exit(1);
	}

	output = input1 + input2;
	mean = (float)output / inputs;
	cout << "The Sum Of These Values Is " << output << endl;
	cout << "The Mean Average Of These Values Is " << mean << endl;
	input3 = 1;
	while (input3 != 0) {
		cout << "Enter Another Number" << endl;
		cin >> input3;
		if (input3 == 0) {
			break;
		}
		inputs++;

		output += input3;
		cout << "The New Sum Is " << output << endl;
		mean = (float)output / inputs;
		cout << "The Mean Average Of These Values Is " << mean << endl;
	}
	cout << "We Don't Take Zeros Here" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}