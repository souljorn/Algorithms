//============================================================================
// Name        : MergeSort.cpp
// Author      : TBotelho
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>

using namespace std;

//merges two subarrys of arr
void merge(int arr[], int l, int m, int r)
{
	//iterators
	int i, j, k;
	//number of elements in subarray 1
	int n1 = m - l + 1;
	//number of elements in subarray 2
	int n2 = r - m;

	//create temp arrays
	int L[n1], R[n2];

	//Copy data to temp arrays
	for(i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];		//Takes the values from the subarray l to n1
	}
	for(j = 0; j < n2;  j++)
	{
		R[j] = arr[(m + 1) + j];  // Takes the values starting from m+1 to n2
	}
	//Merge the temp arrays back into arr
	i = 0;	//initial index of first subarray  1+
	j = 0;	//initial index of second subarry
	k = l;	//initial index of merged subarray

	//while index of first array is less than its size
	//and while the index of the second index is less than its size
	while (i < n1 && j < n2)
	{
		//compare the values of the arrays using the parallel indices
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			//increment the index of the array from which the value was taken
			i++;
		}
		else
		{
			arr[k] =R[j];
			j++;
		}
		k++;			//increment index of array that value was passed
	}//end while

	//Copy the remaining elements of L[] and R[], if there are any
	//There is no conditional because either R[] or L[] has had there elements exhausted
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l,int r)
{
	if(l < r)
	{
		//same as (l+r)/2, but avoids overflow for large l and r
		int m = l +(r-l)/2;

		//Sort first and second halves
		mergeSort(arr, l , m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int main() {


	srand (time(NULL));

	//create an array and fill full of random values
	int size = 1000000;
	int A[size] ;
	int arr_size = sizeof(A)/sizeof(A[0]);
	for (int i = 0; i < size ;i++)
	{
		A[i] = rand() % 100 + 1 ;
	}

	//Print Unsorted array
	for (int i = 0; i < size; i++)
		cout << A[i] << endl;

	//Sort Array
	mergeSort(A, 0, arr_size -1);

	//Print Unsorted array
	for (int i = 0; i < arr_size - 1; i++)
		cout << A[i] << endl;



	return 0;
}
