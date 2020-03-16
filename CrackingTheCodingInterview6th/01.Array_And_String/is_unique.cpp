// 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

#include <iostream>
#include <string> 
#include <map> 

using namespace std;

bool is_unique(string &s) 
{
	// build a hashmap 
	map<char, int> *m = new map<char, int>();

	for(auto it = s.cbegin(); it!=s.cend(); it++)  
	{
		if(m->find(*it) != m->end())
		{
			cout << "Not unique" << endl;
			return false;
		}
		m->insert(pair<char, int>(*it, 1));
	}

	cout << "Unique" << endl;
	return true;
}

int main() {
	string s = "abcdea";

	cout << is_unique(s) << endl;

	return 0;
}

