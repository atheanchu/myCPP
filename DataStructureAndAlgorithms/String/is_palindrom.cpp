#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	int left = 0;
	int right = str.length() - 1;

	while (right > left)
	{
		if (str[left++] != str[right--])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	cout << "Palindrome" << endl;
	// Input string
	string str;
	cout << "Input string -> ";
	getline(cin, str);
	// Check if it is palindrome
	cout << "'" << str << "' is ";
	if (isPalindrom(str))
	{
		cout << "a palindrome";
	}
	else
	{
		cout << "NOT a palindrome";
	}
	cout << endl;
	return 0;
}
