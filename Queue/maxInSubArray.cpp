/*
 * Program to find the first circular tour that visits all petrol pumps
 * Key value pair- petrol and distance (1 unit each)
 */

#include <iostream>
#include <deque>
using namespace std;

void maxInSubArray(int arr[], int n, int k)
{
	//use queue
	deque <int> Q(k);		//note k

	for(int i=0; i<k; i++)
	{
		while(!(Q.empty()) && arr[i] >= arr[Q.back()])	//> or >= check
			Q.pop_back();
		Q.push_back(i);
	}

	for(int i=k; i<n; i++)
	{
		//1. print the front
		cout << arr[Q.front()] << " ";

		//2. remove the front if not in the window before comparing
		while(!(Q.empty()) && (Q.front() <= (i-k)))
			Q.pop_front();

		//3. compare (same as before
		while(!(Q.empty()) && arr[i] >= arr[Q.back()])	//> or >= check
			Q.pop_back();
		Q.push_back(i);
	}
		//4. for last element, print the front as the while exits
	cout << arr[Q.front()] << endl;
}


int main()
{
	int arr[] = {6,3,5,9,12,5,17,19,3,2,8,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int subArraySize = 4;
	maxInSubArray(arr,size, subArraySize);

	printf("La fin");
	return 0;
}
