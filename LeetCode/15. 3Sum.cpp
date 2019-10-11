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

void print2Dvec(vector<vector<int>> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
	{
		for(unsigned int j=0; j<vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;

	//sort
	sort(nums.begin(),nums.end());
	int i,j,k,sum = 0;
	int size = nums.size();

	if(size<3)
		return {};

	//i ranges only the negative elements
	for(i=0; nums[i]<=0 && i<size-2; i++)
	{
		j=i+1;
		k=size-1;
		//remove duplicate i index
		if(i>0 && nums[i] == nums[i-1])
			continue;

		while(j<k)
		{
			sum = nums[i] + nums[j] + nums[k];
			//push in the result
			if(sum == 0)
			{
				res.push_back({nums[i],nums[j],nums[k]});
				j++;
				k--;

				//remove duplicate j index
				while(j<k && nums[j] == nums[j-1])
					j++;
				//remove duplicate k index
				while(j<k && nums[k] == nums[k+1])
					k--;
			}
			else if(sum<0)
				j++;
			else if(sum>0)
				k--;
		}
	}



	return res;
}


int main()
{
	vector<int> vec = {-2,0,0,2,2};
	print(vec);

	vector<vector<int>> res = threeSum(vec);
	print2Dvec(res);


	cout << endl << "La Fin!";
	return 0;
}
