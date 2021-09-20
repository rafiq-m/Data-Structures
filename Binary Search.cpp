#include <iostream>
using namespace std;
#include <stdio.h>


class Search
{
public:
	bool flag = true;
	int binarySearch(int arr[], int left, int right, int key)
	{
		if (left <= right && flag == true)
		{
			int mid = (left + (right)) / 2;
			if (left == right)
			{
				flag = false;
			}
			if (arr[mid] > key)
			{
				binarySearch(arr, left, mid, key);
			}
			else if (arr[mid] < key)
			{
				binarySearch(arr, mid + 1, right, key);
			}
			else
			{
				return mid;
			}
		}
		else
		{
			return -1;
		}
	}
};

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9};
	cout << sizeof(arr)/sizeof(arr[0]) << endl;
	Search* s = new Search();
	int ans = s->binarySearch(arr, 0, sizeof(arr)/sizeof(arr[0]), -1);
	if (ans == -1)
		cout << " Did not find" << endl;
	else
		cout << arr[ans] << endl;
	return 0;
}
