#include <iostream>
#include <vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;

int singleNumber(vector<int>& nums)
{
	//16 ms
	unordered_map<int,int> m;

	for(unsigned int i=0; i<nums.size(); i++)
	{
		m[nums[i]]++;
	}

	for(unsigned int i=0; i<nums.size(); i++)
	{
		if(m[nums[i]] == 1)
			return nums[i];
	}

/*
 	//24 ms
	unordered_set<int> s;
	unordered_set<int>::iterator it;
	for(unsigned int i=0; i<nums.size(); i++)
	{
		it = s.find(nums[i]);
		if(it == s.end())
			s.insert(nums[i]);
		else
			s.erase(it);
	}
	return *(s.begin());
*/
}

int main()
{
	vector<int> vec = {1,2,3,4,5,4,3,1,5};
	cout << singleNumber(vec);

	cout << endl << "La Fin!";
	return 0;
}
