#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	
	//method 1: if given sorted or need output sorted
	//using 2 pointer method

	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());
	vector<int> res;

	int i=0, j=0, k=0;

	while(i<nums1.size() && j<nums2.size())
	{
		if(nums1[i] == nums2[j])
		{
			res.push_back(nums1[i]);
			i++; j++;
		}
		else if(nums1[i]<nums2[j])
			i++;
		else if(nums1[i]>nums2[j])
			j++;
	}
	return res;

	/*//use the smallest vec to fill in the hash map
	if(nums1.size() > nums2.size())
		nums1.swap(nums2);

	vector<int> res;
	unordered_map<int,int> m;

	for(int i=0; i<nums1.size(); i++)
		m[nums1[i]]++;

	for(int i=0; i<nums2.size(); i++)
	{
		if(--m[nums2[i]]>=0)
			res.push_back(nums2[i]);
	}

	return res;
*/


}

void print_vec(vector<int>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vec1 = {4,9,5};
	vector<int> vec2 = {9,4,9,8,4};

	vector<int> res = intersection(vec1,vec2);

	print_vec(res);

	cout << endl << "La Fin!!";
}

