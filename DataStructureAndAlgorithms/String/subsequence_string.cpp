#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> GenerateSubsequences(string str)
{
	// return value
	vector<string> vecString;

	int strLen = str.size();

	// bitCounter is used to check character position
	int bitCounter = pow(2, strLen);

	// check from 000...001 to 111...111 (empty set ignored)
	for (int i = 1; i < bitCounter; ++i)
	{
		// temporary variable to store current subsequences
		string subsequence = "";

		// construct the new subsequence string
		for (int j = 0; j < strLen; j++)
		{
			if (i & (1 << j))
				subsequence += str[j];
		}
		// put it to vector
		vecString.push_back(subsequence);
	}

	return vecString;
}

int main()
{
	cout << "Subsequence Generator" << endl;
	// Input string
	string str;
	cout << "Input string -> ";
	getline(cin, str);
	// Generate subsequences
	vector<string> myvector = GenerateSubsequences(
		str);
	// Show the result to user
	cout << "All subsequences of '" << str;
	cout << "':" << endl;
	for (
		vector<string>::iterator it = myvector.begin();
		it != myvector.end();
		++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}