// 1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

// EXAMPLE
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco eta", etc.)

// Count each characters, and check if there's more than two characters with the odd count. 

#include <iostream>
#include <string> 
#include <map>

using namespace std;

bool check_palin_perm(string &s)
{
	int countOdd = 0;
	map<char, int> *m = new map<char, int>;

	for(int i = 0 ; i < s.length() ; i++) 
	{
		if(s[i] == ' ') 
			continue;
		auto it = m->find(s[i]);
		// ignore the space
		if(it == m->end()) {
			m->insert(pair<char, int>(s[i], 1));
		}
		else 
		{
			it->second ++;
		}
	}

	for(auto it = m->begin() ; it != m->end() ; ++it) 
	{
		if(it->second % 2 == 1) 
		{
			countOdd ++;
			if(countOdd > 1) 
				return false;
		}
	}

	return true;
}

int main() 
{
	string s ; 

	cout << "Enter a string: " ;
	getline(cin, s); 

	if(check_palin_perm(s)) 
		cout << "True";
	else 
		cout << "False";
	cout << endl;

	return 0;
}