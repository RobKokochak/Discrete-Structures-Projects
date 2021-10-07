//==========================================================
//
// Title: Base Conversion
// 
// Description:
//  This C++ app takes input of a decimal number and a 
//	numerical base and converts the decimal number to that
//	base.
//
//==========================================================

#include <iostream>
using namespace std;

void baseConversion(int number, int base);

int main()
{
	baseConversion(15, 2);
	cout << endl;
	baseConversion(38, 16);
	cout << endl;
	baseConversion(54, 6);
	cout << endl;
	baseConversion(19, 8);
	cout << endl;
	baseConversion(27, 3);
}

// Recursive solution - function stacks on top of itself 
// (dividing the original input by 2 each time) 
// until 1st if statement returns false, 
// then goes back and outputs remainders in reverse order

void baseConversion(int number, int base) 
{
	if (number / base != 0){
		baseConversion(number / base, base);
	}
	int result = number % base;

	if (result >= 0 && result < 10)
		cout << result;
	else { 
	// Hexadecimal conversion
		switch(result)
		{
			case 10: cout << 'A';
			break;

			case 11: cout << 'B';
			break;

			case 12: cout << 'C';
			break;

			case 13: cout << 'D';
			break;

			case 14: cout << 'E';
			break;

			case 15: cout << 'F';
			break;
		}
	}
}
