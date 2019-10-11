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
 * Instead of using a set to check duplicate i values(as in commented lines)
 * I used a prev variable for the same functionality
 * brought a speed increase from 52ms to 44ms
 */


int findPairs(vector<int>& nums, int k)
{
	//step 1 is to sort te vector
	sort(nums.begin(),nums.end());

//	unordered_set<int> s;
//	unordered_set<int>::iterator it;

	int counter = 0;
	int j=0;
	int prev_j=0;
	int size = nums.size();
	int prev = INT_MIN;

	for(int i=0; i<size-1;i++)
	{
		//check for repeated numbers
		if(nums[i]==prev)
			continue;

		//logic begin
		j=i+1;
		while(j<size && nums[j]-nums[i]<=k)
		{
			if(nums[j]-nums[i]==k)
			{
				counter++;
				break;		//to break the loop
			}
			j++;
		}
		//insert into set in the end
		//s.insert(nums[i]);
		prev = nums[i];
	}

	return counter;
}


int main()
{
	vector<int> vec = {1,2,2,2,2,2};
	int k = 1;
	print(vec);

	cout << findPairs(vec, k) << endl;


	cout << endl << "La Fin!";
	return 0;
}
