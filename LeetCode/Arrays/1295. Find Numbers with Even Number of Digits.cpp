#include <iostream>
#include <vector>
using namespace std;

int findNumbers(vector<int>& nums)
{
	int res = 0;
	for(int i=0; i<nums.size(); i++)
	{
		int num = nums[i];
		int div = 10;
		int count=0;
		while(num>0)
		{
			if(num > 0)
			{
				count++;
				num = num/div;
			}
		}
		if(count>0 && count%2==0)
			res++;
	}
	return res;
}

int main()
{
	vector<int> v = {12,345,2,6,7896};
	cout << findNumbers(v);
 	return 0;
}
