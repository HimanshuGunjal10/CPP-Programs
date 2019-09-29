#include <iostream>
#include <vector>
#include<algorithm>
#include <stack>
using namespace std;

void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int majorityElement(vector<int>& nums)
{
	int size = nums.size();
	sort(nums.begin(), nums.end());

	return(nums[size/2]);
}
/* //lol. why did I even do this after sorting!!!
int majorityElement(vector<int>& nums)
{
	int size = nums.size();
	sort(nums.begin(), nums.end());
	int count = 0;
	int max_count = 0;
	int maj_element = 0;

	//case when there is only 1 element
	if(size == 1)
		return nums[0];

	for(int i=1; i<size; i++)
	{
		count = 1;
		while(nums[i] == nums[i-1])
		{
			count++;
			i++;
		}
		if(count > max_count)
		{
			max_count = count;
			maj_element = nums[i-1];
//optimization
//			if(max_count>size/2)
//				return maj_element;
		}
		count = 0;
	}
	return maj_element;
}
*/


int main()
{
    vector<int> v;
//    v.push_back(3);
//    v.push_back(24);
//    v.push_back(50);
//    v.push_back(79);
//    v.push_back(79);
//    v.push_back(79);
//    v.push_back(79);

    v.push_back(3);
    v.push_back(2);
    v.push_back(3);



    print(v);

    int res = majorityElement(v);
    cout << res;

    cout << "La Fin";
    return 0;
}
