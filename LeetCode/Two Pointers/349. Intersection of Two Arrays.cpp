#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
	//using unordered sets

	vector<int> res;
	unordered_set<int> s1;
	unordered_set<int> s2;

	for(int i=0; i<nums1.size(); i++)
		s1.insert(nums1[i]);

	//sort(nums2.begin(),nums2.end());
	for(int i=0; i<nums2.size(); i++)
		s2.insert(nums2[i]);

	for(unordered_set<int>::iterator it = s1.begin(); it!=s1.end();it++)
	{
		if(s2.find(*it)!=s2.end())
			res.push_back(*it);
	}

	return res;


	/*//using sets
	vector<int> res;
	set<int> s1;
	set<int> s2;

	for(int i=0; i<nums1.size(); i++)
		s1.insert(nums1[i]);

	//sort(nums2.begin(),nums2.end());
	for(int i=0; i<nums2.size(); i++)
		s2.insert(nums2[i]);

	for(set<int>::iterator it = s1.begin(); it!=s1.end();it++)
	{
		if(s2.find(*it)!=s2.end())
			res.push_back(*it);
	}

	return res;
*/

	/*
	vector<int> res;
	sort(nums1.begin(),nums1.end());
	sort(nums2.begin(),nums2.end());

	int i=0;
	while(i<nums1.size())
	{
		int j = 0;
		while(j<nums2.size() && nums2[j]<=nums1[i])
		{
			if(nums1[i] == nums2[j])
			{
				res.push_back(nums1[i]);
				while(i+1 < nums1.size() && nums1[i]==nums1[i+1])
					i++;
				while(j+1 < nums2.size() && nums2[j]==nums2[j+1])
					j++;
			}
			j++;
		}
		i++;
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

