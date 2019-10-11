#include <iostream>
#include<map>
#include<vector>
using namespace std;

bool isSubArray(int arr1[], int arr2[],int n1, int n2)
{
	//put arr1 in a hashmap // simple map.. 1-1 mapping
	map<int,int> myMap;
	for(int i=0; i<n1; i++)
		myMap[arr1[i]] = arr1[i];

	//check if each element in arr2 is present in the hashmap
	map<int, int> :: iterator it;
	for(int i=0; i<n2; i++)
	{
		//note find returns an iterator
		it = myMap.find(arr2[i]);
		if(it == myMap.end())
			return false;
	}
	return true;
}

int main()
{
	int arr1[] = {1,3,5,7,4,9,10,6};
	int arr2[] = {8,4,9};

	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);


	if(isSubArray(arr1,arr2,n1,n2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	printf("\nLa fin");
	return 0;
}
