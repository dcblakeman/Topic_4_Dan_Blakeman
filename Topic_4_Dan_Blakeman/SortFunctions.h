#pragma once
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

#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

#include<iostream>
#include<ctime>
#include<utility>
#include<cmath>

template<class ItemType>

class SortFunctions
{
public:
	int findIndexOfLargest(const ItemType anArray[], int arraySize);
	void selectionSort(ItemType anArray[], int arraySize);
	void bubbleSort(ItemType anArray[], int arraySize);
	void insertionSort(ItemType anArray[], int arraySize);
	void merge(ItemType anArray[], int first, int mid, int last);
	void mergeSort(ItemType anArray[], int first, int last);
	int partition(ItemType anArray[], int first, int last);
	void quickSort(ItemType anArray[], int first, int last);
	void countSort(ItemType anArray[], int arraySize, int exponent);
	int getMax(int anArray[], int arraySize);
	void radixSort(ItemType anArray[], int arraySize);
};

#endif