#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	return (lower_bound(nums.begin(),nums.end(),target) - nums.begin());
}


int main()
{
    cout << "Hi Hemu" << endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);

    cout << searchInsert(v,8) << endl;

    cout << "La Fin";
    return 0;
}
