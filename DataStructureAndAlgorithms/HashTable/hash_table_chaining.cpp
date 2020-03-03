#include "hash_table_chaining.h"

using namespace std;

int main()
{
	HashTable *hashTable = new HashTable();

	// Check if empty
	if (hashTable->IsEmpty())
		cout << "Hash Table is empty.";
	else
		cout << "Hash Table is not empty.";

	cout << endl;

	cout << "Adding a data " << endl;
	hashTable->Insert(434, "Dylan");

	if (hashTable->IsEmpty())
		cout << "Hash Table is empty.";
	else
		cout << "Hash Table is not empty.";

	// Adding others data
	hashTable->Insert(391, "Dominic");
	hashTable->Insert(806, "Adam");
	hashTable->Insert(117, "Lindsey");
	hashTable->Insert(548, "Cameron");
	hashTable->Insert(669, "Terry");
	hashTable->Insert(722, "Brynn");
	hashTable->Insert(276, "Jody");
	hashTable->Insert(953, "Frankie");
	hashTable->Insert(895, "Vanessa");

	int key = 669;
	cout << "Search value for key " << key << endl;
	string name = hashTable->Search(key);

	if (name != "")
	{
		cout << "Value for key " << key << " is " << name;
	}
	else
	{
		cout << "Value for key " << key << " is not found";
	}
	cout << endl;

	cout << "Remove node of key ";
	cout << key << endl;
	hashTable->Remove(key);
	name = hashTable->Search(key);
	if (name != "")
	{
		cout << "Value for key " << key;
		cout << " is " << name;
	}
	else
	{
		cout << "Value for key " << key;
		cout << " is not found";
	}
	cout << endl;
}
