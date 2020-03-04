#include <algorithm>
#include <iostream>
#include <vector>

class BinaryHeap
{

private:
	int heapSize;
	std::vector<int> vect;

	void ShiftUp(int index);
	void ShiftDown(int index);
	// get the parent's index
	int p(int index) { return index >> 1; }
	// get the left child's index
	int l(int index) { return index << 1; }
	// get the right child's index
	int r(int index) { return (index << 1) + 1; }

public:
	bool IsEmpty();
	void Insert(int key);
	int GetMax();
	int ExtractMax();
};

bool BinaryHeap::IsEmpty()
{
	return heapSize == 0;
}

void BinaryHeap::ShiftUp(int index)
{
	// base case : if index is 1, we've reached root
	if (index == 1)
		return;

	if (vect[index] > vect[p(index)])
	{
		// swap upwards
		std::swap(vect[index], vect[p(index)]);

		// recurse until root
		ShiftUp(p(index));
	}
}

void BinaryHeap::Insert(int key)
{
	// add a new element in vector
	if (heapSize + 1 >= (int)vect.size())
		vect.push_back(0);

	// store the key in the vector last position
	vect[++heapSize] = key;

	ShiftUp(heapSize);
}

int BinaryHeap::GetMax()
{
	return vect[1];
}

void BinaryHeap::ShiftDown(int index) {
	if(index > heapSize) return ;

	int swapId = index;

	// compare with left, if exists
	if(l(index) <= heapSize && vect[index] < vect[l(index)]) 
	{
		swapId = l(index);
	}
	// compare with right, if exists
	if(r(index) <= heapSize && vect[index] < vect[r(index)]) 
	{
		swapId = r(index);
	}

	if(swapId != index) 
	{
		std::swap(vect[index], vect[swapId]);
		ShiftDown(swapId);
	}	
}

int BinaryHeap::ExtractMax() 
{
	// maximum value is in the root
	int maxVal = vect[1];
	// swap with the last existing leaf
	std::swap(vect[1], vect[heapSize--]);
	// fix heap property downward
	ShiftDown(1);

	return maxVal;
}