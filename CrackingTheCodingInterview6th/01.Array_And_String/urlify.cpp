// 1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: If implementing in Java, please use a character array so that you can
// perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith ", 13
// Output: "Mr%20John%20Smith"

// First, I need to know the number of spaces. Then allocate space like length(string) + (spaces * 2)
// Then staring from the last character, move it to the last index of the newly created array. 
// Whenever the space comes, move the index left by 2 and copy '%20'.

#include <iostream>
#include <string> 

using namespace std;

void urlify(string &str, int size)
{
	int numSpaces = 0;
	int index = 0;

	for(int i=0;i<size;i++)
	{
		if(str.at(i) == ' ') 
			numSpaces++;		
	}

	index = ((numSpaces * 2) + size) - 1 ; 

	for(int i = size - 1; i >= 0 ; --i) 
	{
		char c = str.at(i);
		if(c != ' ')
		{
			str[index--] = c; 
		}
		else
		{
			str[index--] = '0';
			str[index--] = '2';
			str[index--] = '%';
		}
	}
}

int main() 
{
	string str = "Mr John Smith                 ";
	urlify(str, 13);
	cout << str << endl;

	return 0;
}

