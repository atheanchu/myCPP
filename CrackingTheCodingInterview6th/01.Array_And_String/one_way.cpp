// 1.5 One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away.
// EXAMPLE
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

// Let's file rules here 

// if the sizes are different by 1, 
// 	0 difference is allowed. 
// if the sizes are same, 
// 	1 difference is allowed. 
// else
// 	false 

#include <iostream>
#include <string> 

using namespace std;

bool one_way(string &s1, string &s2) 
{
	int s1_len = s1.size();
	int s2_len = s2.size();
	int diff = s1_len - s2_len;
	int i=0, j=0;
	bool moved = false;
	if(abs(diff) > 1) 
		return false;
	else if(diff == 1 || diff == -1) 
	{
		string ls = diff == 1 ? s1 : s2; 
		string ss = diff == 1 ? s2 : s1;

		while(i < s1_len && j < s2_len)
		{
			if(ls[i] == ss[j]) 
			{
				i++;
				j++;
			}
			else {
				if(moved) return false;
				i++;
				moved = true;
			}
		}
	}
	else {
		i=0, j=0;
		moved = false;
		while(i < s1_len && j < s2_len) 
		{
			if(s1[i] != s2[j]) 
			{
				if(moved) 
					return false;
				moved = true;
			}
			i++;
			j++;
		}
	}

	return true;
}

int main() 
{
	string s1, s2 ; 

	cout << "Enter the first string: " ;
	getline(cin, s1); 
	cout << "Enter the second string: " ;
	getline(cin, s2); 

	if(one_way(s1, s2)) 
		cout << "True";
	else 
		cout << "False";
	cout << endl;

	return 0;
}