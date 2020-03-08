#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> SearchPattern(string target, string pattern)
{
	vector<int> vecIndex;

	// get length
	int targetLen = target.size();
	int patternLen = pattern.size();

	// perform this only when target is longer than pattern
	if (targetLen >= patternLen)
	{

		for (int i = 0; i <= targetLen - patternLen; i++)
		{
			int j;
			// start comparing the pattern string
			for (j = 0; j < patternLen; j++)
			{
				if (target[i + j] != pattern[j])
					break;
			}
			// if inner for-loop is done, it means that pattern
			// is found
			if (j == patternLen)
			{
				vecIndex.push_back(i);
			}
		}
	}
	return vecIndex;
}

int main()
{
	cout << "Pattern Searching" << endl;
	// Input target string
	string targetStr;
	cout << "Input target string -> ";
	getline(cin, targetStr);
	// Input pattern string
	string patternStr;
	cout << "Input pattern string -> ";
	getline(cin, patternStr);
	// Find the pattern
	vector<int> myvector = SearchPattern(
		targetStr,
		patternStr);
	// Show the result to user
	cout << "'" << patternStr << "' is ";
	if (myvector.size() > 0)
	{
		cout << "found at index ";
		for (vector<int>::iterator it = myvector.begin();
			 it != myvector.end();
			 ++it)
		{
			cout << *it << " ";
		}
	}
	else
	{
		cout << "NOT found";
	}
	cout << endl;

	return 0;
}