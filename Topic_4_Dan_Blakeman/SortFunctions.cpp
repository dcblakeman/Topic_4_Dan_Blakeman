//Daniel Blakeman
//CIS 2201 502
//02-18-2022
//Write a program to display the running time of the sorts described in the chapter:
//Selection Sort
//Bubble Sort
//Insertion Sort
//Merge Sort
//Quick Sort
//Radix Sort

#include<ctime>
#include<iostream>
#include<utility>
#include<cmath>
#include "SortFunctions.h"

using namespace std;

//Variables
const int MAX_SIZE = 100;

//Selection Sort
template<class ItemType>
int SortFunctions<ItemType>::findIndexOfLargest(const ItemType anArray[], int arraySize)
{
	int indexSoFar = 0; // Index of largest entry found so far
	for (int currentIndex = 1; currentIndex < arraySize; currentIndex++)
	{
		if (anArray[currentIndex] > anArray[indexSoFar])
			indexSoFar = currentIndex;
	}

	return indexSoFar;
}

template<class ItemType>
void SortFunctions<ItemType>::selectionSort(ItemType anArray[], int arraySize)
{
	for (int last =  arraySize - 1; last >= 1; last--)
	{
		int largest = findIndexOfLargest(anArray, last + 1);
		swap(anArray[largest], anArray[last]);
	}
}


//Bubble Sort
template<class ItemType>
void SortFunctions<ItemType>::bubbleSort(ItemType anArray[], int arraySize)
{
	bool sorted = false; // False when swaps occur
	int pass = 1;
	while (!sorted && (pass < arraySize))
	{
		sorted = true;
		for (int index = 0; index < arraySize - pass; index++)
		{
			int nextIndex = index + 1;
			if (anArray[index] > anArray[nextIndex])
			{
				//Exchange entries
				swap(anArray[index], anArray[nextIndex]);
				sorted = false;
			}
		}

		pass++;
	}
}


//Insertion Sort
template<class ItemType>
void SortFunctions<ItemType>::insertionSort(ItemType anArray[], int arraySize)
{
	for (int unsorted = 1; unsorted < arraySize; unsorted++)
	{
		ItemType nextItem = anArray[unsorted];
		int location = unsorted;
		while ((location > 0) && (anArray[location - 1] > nextItem))
		{
			//Shift anArray[location - 1] to the right
			anArray[location] = anArray[location - 1];
			location--;
		}

		anArray[location] = nextItem; // Insert next item into sorted region
	}
}

//Merge Sort
//Merge Function
template<class ItemType>
void SortFunctions<ItemType>::merge(ItemType anArray[], int first, int mid, int last)
{
	auto subArrayOne = mid - first + 1;
	auto subArrayTwo = last - mid;

	//Create temporary arrays
	ItemType* leftArray = new ItemType[subArrayOne];
	ItemType* rightArray = new ItemType[subArrayTwo];

	//Copy data to temporary arrays
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = anArray[first + i];

	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = anArray[mid + 1 + j];

	int indexOfSubArrayOne = 0; // Initial index of first sub-array
	int indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = first;

	//Merge the temporary arrays back into one array
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			anArray[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else
		{
			anArray[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	//Copy the remaining elements of the left array
	while (indexOfSubArrayOne < subArrayOne)
	{
		anArray[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	//Copy the remaining elements of the right array
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		anArray[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}



}// End Merge Function

template<class ItemType>
void SortFunctions<ItemType>::mergeSort(ItemType anArray[], int first, int last)
{
	if (first >= last)
		return;
	
		//Sort each half
		auto mid = first + (last - first) / 2; // Index of Midpoint

		//Sort left half of anArray[first to mid]
		mergeSort(anArray, first, mid);

		//Sort right half of anArray[mid+1 to last]
		mergeSort(anArray, mid + 1, last);

		//Merge the two halves
		merge(anArray, first, mid, last);
	
}//End Merge Sort


//Quick Sort
//Partition
template<class ItemType>
int SortFunctions<ItemType>::partition(ItemType anArray[], int first, int last)
{
	ItemType pivot = anArray[first];

	int count = 0;
	for (int i = first + 1; i <= last; i++)
	{
		if (anArray[i] <= pivot)
			count++;
	}

	//Put the pivot element in the correct position
	int pivotIndex = first + count;
	swap(anArray[pivotIndex], anArray[first]);

	//Sort the left and right parts of the pivot element
	int i = first;
	int j = last;

	while (i < pivotIndex && j > pivotIndex)
	{
		while (anArray[i] <= pivot)
			i++;

		while (anArray[j] > pivot)
			j--;

		if (i < pivotIndex && j > pivotIndex)
			swap(anArray[i++], anArray[j++]);
	}
		
	return pivotIndex;

}//End Partition Function

template<class ItemType>
void SortFunctions<ItemType>::quickSort(ItemType anArray[], int first, int last)
{
	//Base Case
	if (first >= last)
		return;

	//Partition the array
	int part = partition(anArray, first, last);

	//Sort the left part
	quickSort(anArray, first, part - 1);

	//Sort the right part
	quickSort(anArray, part + 1, last);


}//End Quick Sort


//Radix Sort
template<class ItemType>
void SortFunctions<ItemType>::countSort(ItemType anArray[], int arraySize, int exponent)
{
	//Output Array
	//Temporary array placeholder
	ItemType* output = new ItemType[arraySize];
	int count[10] = { 0 };

	//Store count of occurrences in count array
	for (int i = 0; i < arraySize; i++)
		count[(anArray[i] / exponent) % 10]++;

	//Add up all of the numbers
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	//Build the output array
	for (int i = arraySize - 1; i >= 0; i--)
	{
		output[count[(anArray[i] / exponent) % 10] - 1] = anArray[i];
		count[(anArray[i] / exponent) % 10]--;
	}

	//Copy the output array to the original array
	for (int i = 0; i < arraySize; i++)
		anArray[i] = output[i];
}

template<class ItemType>
int SortFunctions<ItemType>::getMax(int anArray[], int arraySize)
{
	int max = anArray[0];
	for (int i = 1; i < arraySize; i++)
		if (anArray[i] > max)
			max = anArray[i];
	return max;
}

template<class ItemType>
void SortFunctions<ItemType>::radixSort(ItemType anArray[], int arraySize)
{
	int max = getMax(anArray, arraySize);
	for (int exponent = 1; max / exponent > 0; exponent *= 10)
		countSort(anArray, arraySize, exponent);

}//End Radix Sort