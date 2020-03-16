// 1.2 Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other.
//
// example: abc, cde
//
// - If two strings have different number of characters, always false
// - We can sort both strings and compare, but it's not very efficient.
// - We can count each character in both string and compare.

#include <iostream>
#include <string.h>
#include <map>

using namespace std;

bool check_permutation(string &s1, string &s2)
{
	if (s1.size() != s2.size())
		return false;

	// Build hashmaps for both strings.
	map<char, int> *m1 = new map<char, int>;
	map<char, int> *m2 = new map<char, int>;

	for (auto it = s1.cbegin(); it <= s1.cend(); ++it)
	{
		auto temp = m1->find(*it);
		if (temp == m1->end())
			m1->insert(pair<char, int>(*it, 1));
		else
			temp->second++;
	}

	for (auto it = s2.cbegin(); it <= s2.cend(); ++it)
	{
		auto temp = m2->find(*it);
		if (temp == m2->end())
			m2->insert(pair<char, int>(*it, 1));
		else
			temp->second++;
	}

	for(auto it = m1->begin(); it != m1->end() ; ++it) 
	{
		auto temp = m2->find(it->first);
		if(it->second != temp->second) 
			return false;
	}

	return true;
}

int main() 
{
	string s1= "jin";
	string s2= "jnj";

	cout << check_permutation(s1, s2) << endl;

	return 0;
}