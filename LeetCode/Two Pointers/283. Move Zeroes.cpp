#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
#include <unordered_set>
using namespace std;

void swap(vector<int>& nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void moveZeroes(vector<int>& nums)
{
	int i=0;
	int j=0;

	while(i<nums.size())
	{
		if(nums[i] != 0)
			nums[j++] = nums[i];
		i++;
	}
	for(int i=j;i<nums.size();i++)
		nums[i] = 0;
}


/*
//Why did I swap when I know one value is zero!!
void moveZeroes(vector<int>& nums)
{
	int i = 0;	//itererate over the values
	int j = 0;	//point to the found zero to be swapped
	int size = nums.size();
	while(i<size && nums[i]!=0)
	{
		i++;
		j++;
	}
	//now my i points to either end or to the first index of 0
	if(i==size)
		return;

	//start the swapping
	i++;	//takes care of: when only zero is at lst index
	while(i<size)
	{
		swap(nums,i,j);
		j++;
		i++;
		while(i<size && nums[i]==0)
			i++;
	}
}
*/

void print_vec(vector<int>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = {0,1,0};
	print_vec(vec);
	moveZeroes(vec);
	print_vec(vec);


	cout << endl << "La Fin!!";
}

