#include <iostream>

#define TABLE_SIZE 7

class HashElement
{

public:
	int Key;
	std::string Value;

	HashElement(int key, std::string value)
	{
		this->Key = key;
		this->Value = value;
	}
};

class HashTable
{
private:
	int currentSize = 0;
	HashElement **arr;
	HashElement *deletedElement;

	int hashFunction(int key);

public:
	HashTable();

	void Insert(int key, std::string value);
	std::string Search(int key);
	void Remove(int key);
	bool IsEmpty();
	void PrintHashTable();
};


HashTable::HashTable()
{
	currentSize = 0;

	arr = new HashElement *[TABLE_SIZE];

	for (int i = 0; i < TABLE_SIZE; i++)
		arr[i] = NULL;

	deletedElement = new HashElement(-1, "");
}

int HashTable::hashFunction(int key) {
	return key % TABLE_SIZE;
}

void HashTable::Insert(int key, std::string value)
{
	if (currentSize >= TABLE_SIZE)
		return;

	HashElement *temp = new HashElement(key, value);

	// get the hash key
	int hashIndex = hashFunction(key);

	// find next free space using linear probing
	while (arr[hashIndex] != NULL &&
		   arr[hashIndex]->Key != key &&
		   arr[hashIndex]->Key != -1)
	{
		// linear probing is (hashFunction(key)+1)%TABLE_SIZE
		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}

	if (arr[hashIndex] == NULL ||
		arr[hashIndex]->Key == -1)
	{
		++currentSize;
		arr[hashIndex] = temp;
	}
}

std::string HashTable::Search(int key)
{
	// get the hash key
	int hashIndex = hashFunction(key);

	while (arr[hashIndex] != NULL && arr[hashIndex]->Key != deletedElement->Key)
	{
		// if the element is found, return the value
		if (arr[hashIndex]->Key == key)
			return arr[hashIndex]->Value;

		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}

	// not found, return empty string
	return "";
}

void HashTable::Remove(int key)
{
	// get the hash key
	int hashIndex = hashFunction(key);

	while (arr[hashIndex] != NULL && arr[hashIndex]->Key != deletedElement->Key)
	{
		// we found the element
		if (arr[hashIndex]->Key == key)
		{
			arr[hashIndex] = deletedElement;
			--currentSize;
			// no need to search anymore
			return;
		}

		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}
	// if key is not found just do nothing
}

bool HashTable::IsEmpty() {
	return currentSize == 0 ;
}

void HashTable::PrintHashTable() {
	// Iterate through array 
	for(int i=0;i<currentSize;i++) {
		if(arr[i] != NULL && arr[i]->Key != -1) {
			std::cout << "Cell : " << i;
			std::cout << " Key  : " << arr[i]->Key;
			std::cout << " Value: " << arr[i]->Value;
			std::cout << std::endl;		
		}
	}
}