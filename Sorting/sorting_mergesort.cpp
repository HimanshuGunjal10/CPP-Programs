#include <iostream>
#include <cstdlib>
using namespace std;

void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//worst cse: O(nlog(n))
void merge(int arr[], int low, int mid, int high)
{
	int nL = mid - low + 1;
	int nR = high - mid;
	int left[nL], right[nR];

	for(int i=0; i<nL; i++)
		left[i] = arr[low+i];
	for(int j=0; j<nR; j++)
		right[j] = arr[mid+1+j];

	int i=0;
	int j=0;
	int k=low;	//imp

	while(i<nL && j<nR)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else if(right[j]<left[i])
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<nL)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<nR)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
}


void merge_sort(int arr[], int low, int high)
{
	if(low<high)
	{
		int mid = low + (high-low)/2;

		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);

		merge(arr,low,mid,high);
	}
}


int main()
{
	int arr[] = {1,7,4,8,2,4,5,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	print(arr,size);
	merge_sort(arr,0,size-1);
	print(arr,size);


	return 0;
}
