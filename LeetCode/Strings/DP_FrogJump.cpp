#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int minJumps(int arr[], int n)
{
	int memo[n];
	int min;

	memo[n-1] = 0;

	for(int i=n-2;i>=0; i--)
	{
		if(arr[i]==0)
			memo[i] = INT_MAX;	//cant reach from this point as its 0
		else if(arr[i]+i >= n-1)	//can reah the end from this point
			memo[i] = 1; 			//1 to keep it minimum. if get here again, problem is solved
		else
		{
			min = INT_MAX;
			for(int j= i+1; j<n && j<=arr[i]+i; j++)
			{
				if(min > memo[j])
					min = memo[j];
			}
			//handling overflow
			if(min == INT_MAX)
				memo[i] = INT_MAX;
			else
				memo[i] = min+1;
		}
	}
	return memo[0] == INT_MAX ? -1 : memo[0];
}

int main()
{
	int arr[] = { 1, 3, 6, 1, 0, 9 };
    int size = sizeof(arr) / sizeof(int);

    cout << minJumps(arr,size);

	cout << "\nLa Fin!!";
}
