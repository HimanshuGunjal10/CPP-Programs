#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& A)
{
	 //lol same code for the problem 162 and 852 as well
	//Binary Search O(log N)
	int low =0, high = A.size()-1;
	while(low<high)
	{
		int mid = low + (high-low)/2;
		if(A[mid]<A[mid+1])
			low = mid+1;
		else
			high = mid;
	}
	return low;
/*
	//O(N)
	int i=0;
	while(A[i]<A[i+1])
		i++;
	return i;
*/
}


int main()
{
	vector<int> vec = {0,2,3,5,4};
	cout << peakIndexInMountainArray(vec);

	cout << "\nLa Fin!!";
}
