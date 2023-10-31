#pragma once
#include <iostream>
using namespace std;

class CHeapSort
{
public:

	int comparisonsHeapSort = 0;

	void heapify(int arr[], int tamanoArray, int nodoPadre);
	void heapSort(int arr[], int tamanoArray);
	void printArray(int arr[], int tamanoArray);
	int comparisons();
};