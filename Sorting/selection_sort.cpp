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
void selection_sort(int arr[], int size)
{
	int min_index =0;

	for(int i=0; i<size; i++)
	{
		min_index = i;
		for(int j=i; j<size; j++)
		{
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr,i,min_index);
	}
}

int main()
{

	int arr[] = {5,3,7,9,2,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	print(arr,size);
	selection_sort(arr,size);
	print(arr,size);

	cout << "Fin";
	return 0;
}
