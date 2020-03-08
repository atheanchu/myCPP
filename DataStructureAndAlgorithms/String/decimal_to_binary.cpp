#include <iostream>
#include <string>

using namespace std;

string DecimalToBinaryString(int decimalNumber)
{
	// initial result
	string binaryString = "0";

	// Only perform this when decimalNumber is greater than 0
	if (decimalNumber > 0)
	{
		// reset result
		binaryString = "";
		// declare a variable for division process
		div_t dv{};
		// initialize the division quote
		dv.quot = decimalNumber;
		// perform these procedures untile the quot is 0
		do
		{
			dv = div(dv.quot, 2);
			binaryString = to_string(dv.rem) + binaryString;
		} while (dv.quot);
	}

	return binaryString;
}

int main()
{
	cout << "Decimal To Binary String" << endl;
	// Input a decimal number
	int decNum;
	cout << "Input a decimal number -> ";
	cin >> decNum;
	// Convert to binary string
	string binaryString = DecimalToBinaryString(decNum);
	// Show the result to user
	cout << "Binary string of " << decNum;
	cout << " is '" << binaryString;
	cout << "'" << endl;

	return 0;
}