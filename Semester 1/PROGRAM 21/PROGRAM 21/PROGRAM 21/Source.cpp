#include <iostream>
#include <algorithm>

using namespace std;

int findLargestValue(int in[]);
int findLargestValueLocation(int in[]);
const int arraySize = 5;



int main() {

	int inputs[5];
	cout << "Please Enter 5 Integers" << endl;

	for (int i = 0; i < 5; i++)
	{
		cin >> inputs[i];
	}

	
	
	cout << "The Values Of This Array in Ascending Order" << endl;
	sort(inputs, inputs + arraySize);
	for (int i = 0; i < 5; i++)
	{
		cout << inputs[i] << " ";
	} 
	cout <<endl<< "The Values Of This Array in Descending Order" << endl;
	sort(inputs, inputs + arraySize,greater<int>());
	for (int i = 0; i < 5; i++)
	{
		cout << inputs[i] << " ";
	}

	int Largest = findLargestValue(inputs);
	int location = findLargestValueLocation(inputs);
	cout << endl << "The Largest Value In The Array Is " << Largest << " This Value Is In Position " << location << endl;

	return 0;
}

int findLargestValue(int in[]) {
	int temp = in[0];
	for (int i = 0; i < 5; i++) {
		if (temp < in[i]) {
			temp = in[i];
		}
	}
	return temp;
}

int findLargestValueLocation(int in[]) {
	int temp = in[0];
	int index = 0;
	for (int i = 0; i < 5; i++) {
		if (temp < in[i]) {
			index = i;
		}
	}
	return index;
}
