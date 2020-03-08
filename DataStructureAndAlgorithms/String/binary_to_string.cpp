#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int BinaryStringToDecimal(string binaryString)
{
	// result
	int decimalNumber = 0;
	// current power base
	int n;

	// declare reverse iterator
	string::reverse_iterator it;

	for (it = binaryString.rbegin(), n = 0;
		 it != binaryString.rend();
		 it++, n++)
	{
		char c = *it;
		if (c == '1')
		{
			decimalNumber += pow(2, n);
		}
	}

	return decimalNumber;
}

int main()
{
	cout << "Binary String To Decimal" << endl;
	// Input binary string
	string binaryString;
	cout << "Input binary string -> ";
	getline(cin, binaryString);
	// Convert to decimal
	int decNumber = BinaryStringToDecimal(
		binaryString);
	// Show the result to user
	cout << "Decimal of '" << binaryString;
	cout << "' is " << decNumber << endl;
	return 0;
}
