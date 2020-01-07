#include <iostream>
#include <cstdlib>
using namespace std;

void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low-1;

	for(int j=low; j<high; j++)			//did j=0 , j<=... only mistake
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);

	return (i+1);
}

//worstcase O(n2), avg case: O(nlogn)
void quick_sort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pi = partition(arr,low,high);
		quick_sort(arr, low, pi-1);
		quick_sort(arr,pi+1, high);
	}
}

int main()
{
	int arr[] = {1,7,4,8,2,4,5,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	print(arr,size);
	quick_sort(arr,0,size-1);
	print(arr,size);


	return 0;
}
