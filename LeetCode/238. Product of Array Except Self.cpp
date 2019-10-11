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

vector<int> productExceptSelf(vector<int>& nums)
{
	int mul = 1;
	int oneOrLessZeroes = 0;
	int zeroIndex = -1;	//any value other than 0 to size-1

	//1. Storing the mul value
	for(unsigned int i=0; i<nums.size(); i++)
	{
		if(nums[i]==0)
		{
			oneOrLessZeroes++;
			zeroIndex = i;
		}

		if(oneOrLessZeroes > 1)
		{
			vector<int> res;
			res.assign(nums.size(),0);			//*** returns size number of zeroes
			return res;
		}

		if(nums[i] != 0)
			mul *= nums[i];
	}

	vector<int>res;
	for(unsigned int i=0; i<nums.size();i++)
	{
		if(oneOrLessZeroes == 1)
		{
			(i == zeroIndex)? res.push_back(mul) : res.push_back(0);

		}
		else
			res.push_back(mul/nums[i]);
	}
	return res;
}


int main()
{
	vector<int> vec = {9,0,-2};
	print(vec);

	vector<int> res = productExceptSelf(vec);
	print(res);

	cout << endl << "La Fin!";
	return 0;
}
