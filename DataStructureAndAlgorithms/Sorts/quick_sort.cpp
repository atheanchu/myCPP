#include <iostream>

using namespace std;

int Partition(int arr[], int startIndex, int endIndex)
{
	// Set the first item as pivot
	int pivot = arr[startIndex];
	// Left sublist and right sublist are initially empty
	int middleIndex = startIndex;

	for (int i = startIndex + 1; i <= endIndex; i++)
	{
		if (arr[i] < pivot)
		{
			middleIndex++;
			// middleIndex is a member of right sublist
			swap(arr[i], arr[middleIndex]);
		}
	}
	// Swap arr[middleIndex] with pivot so the pivot will be
	// in the correct position
	swap(arr[middleIndex], arr[startIndex]);
	// return the index of pivot to be used by the next quick sot
	return middleIndex;
}

void QuickSort(int arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int pivotIndex = Partition(arr, startIndex, endIndex);
		QuickSort(arr, startIndex, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, endIndex);
	}
}

int main()
{
	cout << "Quick Sort" << endl;
	// Initialize a new array
	int arr[] = {25, 21, 12, 40, 37, 43, 14, 28};
	int arrSize = sizeof(arr) / sizeof(*arr);
	// Display the initial array
	cout << "Initial array: ";
	for (int i = 0; i < arrSize; ++i)
		cout << arr[i] << " ";
	cout << endl;
	// Sort the array with QuickSort algorithm
	QuickSort(arr, 0, arrSize - 1);
	// Display the sorted array
	cout << "Sorted array : ";
	for (int i = 0; i < arrSize; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}