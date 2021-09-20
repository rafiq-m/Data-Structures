#pragma once
using namespace std;
#include <iostream>

class Sorting
{
	void merge(int arr[], int l, int m, int r)
	{
		int i, j, k;
		int n1 = m - l + 1;
		int n2 = r - m;
		
		int* L = new int[n1];
		int* R = new int[n2];

		/* Copy data to temp arrays L[] and R[] */
		for (i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1 + j];

		/* Merge the temp arrays back into arr[l..r]*/
		i = 0; // Initial index of first subarray 
		j = 0; // Initial index of second subarray 
		k = l; // Initial index of merged subarray 
		while (i < n1 && j < n2)
		{
			if (L[i] <= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		/* Copy the remaining elements of L[], if there
		   are any */
		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		/* Copy the remaining elements of R[], if there
		   are any */
		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
		for (int c = 0; c < 6; c++)
		{
			cout << arr[c] << " ";
		}
		cout << endl;
	}


public:
	void mergeSort(int arr[], int l, int r)
	{
		if (l < r)
		{

			int m = (l+r)/ 2;

			mergeSort(arr, l, m);
			mergeSort(arr, m + 1, r);

			merge(arr, l, m, r);
		}
	}
	void printArray(int A[], int size)
	{
		int i;
		for (i = 0; i < size; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
};

int main(){
int arr[] = { 9,8,7,6,5,4};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	Sorting* s = new Sorting();
	printf("Given array is \n");
	s->printArray(arr, arr_size);

	s->mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	s->printArray(arr, arr_size);
	return 0;
}