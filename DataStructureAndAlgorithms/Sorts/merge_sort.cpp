#include <iostream>

using namespace std;

void Merge(int arr[], int startIndex, int middleIndex, int endIndex)
{
	int totalElement = endIndex - startIndex + 1;
	int *tempArray = new int[totalElement];
	// index of left subarray
	int leftIndex = startIndex;
	// index of right subarray
	int rightIndex = middleIndex + 1;
	// index of merged array
	int mergedIndex = 0;

	while (leftIndex <= middleIndex && rightIndex <= endIndex)
	{
		if (arr[leftIndex] <= arr[rightIndex])
		{
			tempArray[mergedIndex] = arr[leftIndex];
			leftIndex++;
		}
		else
		{
			tempArray[mergedIndex] = arr[rightIndex];
			rightIndex++;
		}
		mergedIndex++;
	}

	// if anything remaining in the left
	while (leftIndex <= middleIndex)
	{
		tempArray[mergedIndex] = arr[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	// if anything remaining in the right
	while (rightIndex <= endIndex)
	{
		tempArray[mergedIndex] = arr[rightIndex];
		++rightIndex;
		++mergedIndex;
	}

	// now the merged array is sorted.
	// put it back into the original array
	for (int i = 0; i < totalElement; i++)
	{
		arr[startIndex + i] = tempArray[i];
	}

	delete[] tempArray;

	return;
}

void MergeSort(int arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int middleIndex = (startIndex + endIndex) / 2;
		MergeSort(arr, startIndex, middleIndex);
		MergeSort(arr, middleIndex + 1, endIndex);
		Merge(arr, startIndex, middleIndex, endIndex);
	}

	return;
}

int main()
{
	cout << "Merge Sort" << endl;
	// Initialize a new array
	int arr[] = {7, 1, 5, 9, 3, 6, 8, 2};
	int arrSize = sizeof(arr) / sizeof(*arr);
	// Display the initial array
	cout << "Initial array: ";
	for (int i = 0; i < arrSize; ++i)
		cout << arr[i] << " ";
	cout << endl;
	// Sort the array with MergeSort algorithm
	MergeSort(arr, 0, arrSize - 1);
	// Display the sorted array
	cout << "Sorted array : ";
	for (int i = 0; i < arrSize; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
