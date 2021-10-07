//==========================================================
//
// Title: Brute Force Code Cracker
// 
// Description:
//	Given an input string which is encrypted using a
//	cypher, this program will run through all the possible
//	decryptions using the 25 shifts of the alphabet.
//	
//==========================================================

#include <iostream>
using namespace std;
#include <string>

int main()
{
	string string1 = "Lo cebo dy nbsxu iyeb Yfkvdsxo";

	for (int shift = 1; shift < 26; shift++) // do 25 shifts: 1 for each letter in alphabet
	{
		for (int i = 0; i < string1.length(); i++) // one loop for each character in string
		{
			if (string1[i] != 32){
				string1[i] += 1;
				if (string1[i] == 91) // if the character exceeds Z, go back to A
					string1[i] = 65;
				if (string1[i] == 123) // if the char exceeds z, go back to a
					string1[i] = 97;
			}
		}
	cout << "Shift of " << shift << ": " << string1 << endl;
	}
}