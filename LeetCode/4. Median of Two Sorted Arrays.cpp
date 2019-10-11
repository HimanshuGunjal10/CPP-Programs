#include <iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
#include<algorithm>
using namespace std;

void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

/*
 * https://www.youtube.com/watch?v=LPFhl65R7ww
 */

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	double result=0;

	int len1 = nums1.size();
	int len2 = nums2.size();

	//1st array should be smaller. If not call the function again reversing inputs
	if(len2<len1)
		return findMedianSortedArrays(nums2,nums1);

	int low = 0;
	int high = len1;

	//binary search
	while(low<=high)
	{
		//important how to split
		int partitionX = (low+high)/2;
		int partitionY = (len1+len2+1)/2-partitionX;

		int maxLeftX = (partitionX==0)? INT_MIN : nums1[partitionX-1];
		int minRightX = (partitionX==len1)? INT_MAX : nums1[partitionX];

		int maxLeftY = (partitionY==0)? INT_MIN : nums2[partitionY-1];;
		int minRightY = (partitionY==len2)? INT_MAX : nums2[partitionY];

		//correct partition found
		if(maxLeftX<=minRightY && maxLeftY <= minRightX)
		{
			if((len1+len2)%2 == 0)
				return ( (double)max(maxLeftX,maxLeftY) + min(minRightX, minRightY) )/2;
			else
				return (double)max(maxLeftX,maxLeftY);
		}
		else if(maxLeftX>minRightY)
			high = partitionX-1;
		else if(maxLeftY>minRightX)
			low = partitionX+1;
	}

	return result;
}


int main()
{
	vector<int> vec1 = {1,2,3,4};
	vector<int> vec2 = {5,6,7,8};

	print(vec1);
	print(vec2);

	cout << "median: " << findMedianSortedArrays(vec1,vec2);

	cout << endl << "La Fin!";
	return 0;
}
