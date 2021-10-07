#include <iostream>
using namespace std;
#include <string>

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main()
{

	string input = "0111101";
	cout << "Input message: " << input << "\n";
	int s1 = int(input[0]) - 48;
	int s2 = int(input[1]) - 48;
	int m3 = int(input[2]) - 48;
	int s4 = int(input[3]) - 48;
	int m5 = int(input[4]) - 48;
	int m6 = int(input[5]) - 48;
	int m7 = int(input[6]) - 48;
	
	int s1Check = (s1+m3+m5+m7) % 2;
	int s2Check = ((s2+m3+m6+m7) % 2) * 2;
	int s4Check = ((s4+m5+m6+m7) % 2) * 4;

	int checkResult = s1Check+s2Check+s4Check;

	switch (checkResult)
	{
		case 0:
		cout << "No incorrect bits.\n";
		break;

		case 1:
		cout << "S1 bit incorrect.\n";
		if (s1 == 1)
			s1 = 0;
		else
			s1 = 1;
		break;

		case 2:
		cout << "S2 bit incorrect.\n";
		if (s2 == 1)
			s2 = 0;
		else
			s2 = 1;
		break;

		case 3:
		cout << "M3 bit incorrect.\n";
		if (m3 == 1)
			m3 = 0;
		else
			m3 = 1;
		break;

		case 4:
		cout << "S4 bit incorrect.\n";
		if (s4 == 1)
			s4 = 0;
		else
			s4 = 1;
		break;

		case 5:
		cout << "M5 bit incorrect.\n";
		if (m5 == 1)
			m5 = 0;
		else
			m5 = 1;
		break;

		case 6:
		cout << "M6 bit incorrect.\n";
		if (m6 == 1)
			m6 = 0;
		else
			m6 = 1;
		break;

		case 7:
		cout << "M7 bit incorrect.\n";
		if (m7 == 1)
			m7 = 0;
		else
			m7 = 1;
		break;
	}

	if (checkResult != 0)
		cout << "Corrected code: " <<s1<<s2<<m3<<s4<<m5<<m6<<m7 << endl;

	string m3str = to_string(m3);
	string m5str = to_string(m5);
	string m6str = to_string(m6);
	string m7str = to_string(m7); 

	string postMessageStr[4] = {m3str+m5str+m6str+m7str};
	int postMessageInt = stoi(*postMessageStr);
	cout << "Decimal number message: " << binaryToDecimal(postMessageInt);
}