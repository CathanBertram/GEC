#include <iostream>

using namespace std;

int main() {
	//array with 5 rows and 2 columns

	int myNumbers[5][2] = {
	{0,0},
	{1,2},
	{2,4},
	{3,6},
	{4,8}
	};

	//output each array elements value
	for (int row = 0; row < 5 ; row ++)
	{
		for (int column = 0; column < 2; column++)
		{
			cout << "myNumbers[" << row << "][" << column << "]:";
			cout << myNumbers[row][column] << endl;
		}
	}
	return 0;
}