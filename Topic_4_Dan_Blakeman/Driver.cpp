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
#include "SortFunctions.cpp"
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	//Variables
	int intArray3[] = { 35, 100, 2, 44, 68, 43, 20, 25, 11, 3, 112, 57, 1, 5, 10, 4, 3, 15, 7, 8 , 14, 67, 54, 13, 45, 68 };
	int arraySize3 = sizeof(intArray3) / sizeof(intArray3[0]);
	double overallTime = 0;

	//Instance
	SortFunctions<int> sort;
	
	//Selection Sort Time
	clock_t selectionStart = clock();
	sort.selectionSort(intArray3, arraySize3);
	clock_t selectionFinish = clock();
	overallTime = static_cast<double>(selectionFinish - selectionStart) / CLOCKS_PER_SEC;
	cout << "Selection Sort Time:" << fixed << overallTime << setprecision(5) << endl;

	//Bubble Sort Time
	clock_t bubbleStart = clock();
	sort.bubbleSort(intArray3, arraySize3);
	clock_t bubbleFinish = clock();
	overallTime = static_cast<double>(bubbleFinish - bubbleFinish) / CLOCKS_PER_SEC;
	cout << "Bubble Sort Time: " << fixed << overallTime << setprecision(5) << endl;

	//Insertion Sort Time
	clock_t insertionStart = clock();
	sort.insertionSort(intArray3, arraySize3);
	clock_t insertionFinish = clock();
	overallTime = static_cast<double>(insertionFinish - insertionStart) / CLOCKS_PER_SEC;
	cout << "Insertion Sort Time: " << fixed << overallTime << setprecision(5) << endl;
	
	//Merge Sort Time
	clock_t mergeStart = clock();
	sort.mergeSort(intArray3, 0, arraySize3 - 1);
	clock_t mergeFinish = clock();
	overallTime = static_cast<double>(mergeFinish - mergeStart) / CLOCKS_PER_SEC;
	cout << "Merge Sort Time: " << fixed << overallTime << setprecision(5) << endl;
	
	//Quick Sort Time
	clock_t quickStart = clock();
	sort.quickSort(intArray3, 0, arraySize3 - 1);
	clock_t quickFinish = clock();
	overallTime = static_cast<double>(quickFinish - quickStart) / CLOCKS_PER_SEC;
	cout << "Quick Sort Time: " << fixed << overallTime << setprecision(5) << endl;
	
	//Radix Sort Time
	clock_t radixStart = clock();
	sort.radixSort(intArray3, arraySize3);
	clock_t radixFinish = clock();
	overallTime = static_cast<double>(radixFinish - radixStart) / CLOCKS_PER_SEC;
	cout << "Radix Sort Time: " << fixed << overallTime << setprecision(5) << endl;

}