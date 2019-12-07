#include <iostream>

using namespace std;
void outputResults(int numOfOdd, int oddTotal, int numOfEven, int evenTotal);
bool oddOrEven(int num);
int numOfEven=0;
int oddTotal = 0;
int numOfOdd = 0;
int evenTotal = 0;
int numbers[10];
int main() {
	int i;
	for (i = 0; i<10 ; i++)
	{
		cout << "Enter An Integer" << endl;
		cin >> numbers[i];
		if (oddOrEven(numbers[i])==true) {
			numOfEven++;
		}
		else
		{
			numOfOdd++;
		}
	
	}

	outputResults(numOfOdd, oddTotal, numOfEven, evenTotal);


	return 0;
}
bool oddOrEven(int num) {
	if (num % 2 == 0) {
		evenTotal += num;
		return true;
	}
	else if (num % 2 == 1) {
		oddTotal+= num;
		return false;
	}

}

void outputResults(int numOfOdd, int oddTotal, int numOfEven, int evenTotal) {

	cout << "The Number Of Odd Numbers Is " << numOfOdd << endl << "The Number Of Even Numbers Is " << numOfEven << endl;
	cout << "The Total Value Of The Odd Numbers Is " << oddTotal << endl << "The Total Value Of The Even Numbers Is " << evenTotal << endl;
}