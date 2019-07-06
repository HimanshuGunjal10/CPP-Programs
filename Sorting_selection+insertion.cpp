#include <iostream>
#include <cstdlib>
using namespace std;

void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void selection_sort(int arr[], int size)
{
	int min;
	int min_index;

	for(int i=0; i<size; i++)
	{
		min = arr[i];
		min_index = i;
		for(int j=i; j<size; j++)
		{
			if(arr[j]<min)
			{
				min = arr[j];
				min_index = j;
			}
		}
		swap(arr[i],arr[min_index]);		//#include <stdlib>
	}
}

void insertion_sort(int arr[], int size)
{
	int hole;
	int min;
	for(int i=1; i<size; i++)
	{
		min = arr[i];
		hole = i;
		while(arr[hole-1]>min && hole>0)
		{
			arr[hole] = arr[hole-1];
			hole--;
		}
		arr[hole]=min;
	}
}


int main()
{
	int arr[] = {1,7,4,8,2,4,5,9};
	int size = sizeof(arr)/sizeof(int);

	print(arr,size);
	//selection_sort(arr,size);
	//insertion_sort(arr,size);
	print(arr,size);


	return 0;
}
