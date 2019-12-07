#include <iostream>

using namespace std;

int findSmallestValue(int in[]);
int findSmallestValueLocation(int in[]);

int main() {
	
	int inputs[10];
	int output[10][2]{
		{inputs[0],1},
		{inputs[1],2},
		{inputs[2],3},
		{inputs[3],4},
		{inputs[4],5},
		{inputs[5],6},
		{inputs[6],7},
		{inputs[7],8},
		{inputs[8],9},
		{inputs[9],10}
	};
	for (int i = 0; i < 10; i++)
	{
		cout << "Input an Integer" << endl;
		cin >> inputs[i];
	}

	int smallest = findSmallestValue(inputs);
	int location = findSmallestValueLocation(inputs);
	cout << "The Smallest Value In The Array Is " << smallest <<" This Value Is In Position " << location << endl;
	return 0;
}
int findSmallestValue(int in[]) {
	int temp = in[0];
	for (int i = 0; i < 10; i++) {
		if (temp > in[i]) {
			temp = in[i];
		}
	}
	return temp;
}
int findSmallestValueLocation(int in[]) {
	int temp = in[0];
	int index = 0;
	for (int i = 0; i < 10; i++) {
		if (temp > in[i]) {
			index++;
		}
	}
	return index;
}