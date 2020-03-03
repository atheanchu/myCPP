#include <iostream>
#include <list>

#define TABLE_SIZE 7

class HashTable
{

private:
	std::list<std::pair<int, std::string>> tableList[TABLE_SIZE];
	int HashFunction(int key);

public:
	HashTable() {}

	void Insert(int key, std::string value);
	std::string Search(int key);
	void Remove(int key);
	bool IsEmpty();
};

int HashTable::HashFunction(int key) {
	return key % TABLE_SIZE ;
}

void HashTable::Insert(int key, std::string value) {
	bool isKeyFound = false;

	// Get the hash key 
	int hashKey = HashFunction(key);

	// Iterate through chaining node in selected cell
	// If key is foiund, update the value of that key. 
	for(auto &keyValue : tableList[hashKey]) {
		if(keyValue.first == key) {
			isKeyFound = true;
			keyValue.second = value;
		}
	}

	// If key is not found, append at the back
	if(!isKeyFound) {
		tableList[hashKey].emplace_back(key,value);
	}
}

std::string HashTable::Search(int key) {
	// get the hashkey
	int hashKey = HashFunction(key);

	for(auto &keyValue : tableList[hashKey]) {
		if(keyValue.first == key) {
			return keyValue.second;
		}
	}

	// not found 
	return "";
}

void HashTable::Remove(int key) {
	int hashKey = HashFunction(key) ;

	// Get the cell
	auto &cell = tableList[hashKey];

	for(auto it = cell.begin() ; it != cell.end() ; ++it) {
		if(it->first == key) {
			cell.erase(it);
			break;
		}
	}
}

bool HashTable::IsEmpty() {
	int totalElement = 0;

	for(int i=0 ; i<TABLE_SIZE ; i++) {
		totalElement += (int)tableList[i].size();

		if(totalElement > 0) return false;
	}

	return true;
}