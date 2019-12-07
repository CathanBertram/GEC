#include <iostream>

using namespace std;

void add2ToNumber( int num );

int main() {
	int myNum = 0;
//output the contents of myNum before the function call
	cout<<"Main [before]: myNum = " << myNum << endl;

	//call the function which will add 2 to the value
	add2ToNumber(  myNum );

	//output the contents of myNum after the function call
	cout << "Main [After]: myNum = " << myNum << endl;
	return 0;
}

void add2ToNumber( int num ) {
	//add 2 to the variable passed in
	num += 2;

	//output the contents of num within the function
	cout << "FUNCTION:num=" << num << endl;
}