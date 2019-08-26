#include<iostream>
using namespace std;

void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int arr[], int i, int min_index)
{
	int temp = arr[i];
	arr[i] = arr[min_index];
	arr[min_index] = temp;
}

//Selection sort
void insertion_sort(int arr[], int size)
{
	int j=0;
	for(int i=1; i<size; i++)
	{
		int insert_this = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>insert_this)	// and not arr[j]>arr[i] as it changes
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = insert_this;
	}
}

int main()
{

	int arr[] = {5,3,7,9,2,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	print(arr,size);
	insertion_sort(arr,size);
	print(arr,size);

	cout << "Fin";
	return 0;
}
