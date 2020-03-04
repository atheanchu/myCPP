#include "binary_heap.h"

using namespace std;

int main()
{
	BinaryHeap *priorityQueue = new BinaryHeap();

	// Check if the queue is empty
	// it should be TRUE
	cout << "Is queue empty? ";
	bool b = priorityQueue->IsEmpty();
	if (b)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;
	// Insert a new element
	priorityQueue->Insert(14);
	cout << "Insert 14 to queue" << endl;

	b = priorityQueue->IsEmpty();
	if (b)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl;

	// Insert others elements
	priorityQueue->Insert(53);
	priorityQueue->Insert(8);
	priorityQueue->Insert(32);

	// Peek the maximum element
	// It should be 53
	cout << "GetMax() = ";
	cout << priorityQueue->GetMax();
	cout << endl;

	// Extract maximum element
	cout << "ExtractMax() = ";
	cout << priorityQueue->ExtractMax();
	cout << endl;

	return 0;
}