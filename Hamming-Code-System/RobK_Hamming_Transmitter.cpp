#include <iostream>
#include <string>
using namespace std;

string decToBinary(int n)
{
    // array to store binary number
    int binaryNumRev[32];
 	string binaryNum;
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNumRev[i] = n % 2;
        n = n / 2;
        i++;
    }
 	// creating and returning binary number by iterating in reverse
    for (int j = i - 1; j >= 0; j--)
        binaryNum.append(to_string(binaryNumRev[j]));
    return binaryNum;
}

int main()
{
	int decNumber = 12;
	int s1=0,s2=0,m3=0,s4=0,m5=0,m6=0,m7=0;
	string binNumber = decToBinary(decNumber);

	cout << "Original Decimal Number: " << decNumber << endl;

	if (binNumber.length() == 1)
	{
		m3 = 0;
		m5 = 0;
		m6 = 0;
		m7 = int(binNumber[0]) - 48;
	}
	else if (binNumber.length() == 2)
	{
		m3 = 0;
		m5 = 0;
		m6 = int(binNumber[0]) - 48;
		m7 = int(binNumber[1]) - 48;
	}
	else if (binNumber.length() == 3)
	{
		m3 = 0;
		m5 = int(binNumber[0]) - 48;
		m6 = int(binNumber[1]) - 48;
		m7 = int(binNumber[2]) - 48;
	}
	else
	{
		m3 = int(binNumber[0]) - 48;
		m5 = int(binNumber[1]) - 48;
		m6 = int(binNumber[2]) - 48;
		m7 = int(binNumber[3]) - 48;
	}

	s1 = (m3 + m5 + m7) % 2;
	s2 = (m3 + m6 + m7) % 2;
	s4 = (m5 + m6 + m7) % 2;

	string hamCode = "";
	hamCode.append(to_string(s1));
	hamCode.append(to_string(s2));
	hamCode.append(to_string(m3));
	hamCode.append(to_string(s4));
	hamCode.append(to_string(m5));
	hamCode.append(to_string(m6));
	hamCode.append(to_string(m7));

	cout << "Hamming Code to Transmit: " << hamCode << endl;

}