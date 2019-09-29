#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	int max_endingHere = 0;
	int max_soFar = 0;

	int i = 0;
	int size = nums.size();

	if(size == 0)
		return 0;
	if(size == 1)
		return nums[0];


	for(i=0; i<size; i++)
	{
		if(i==0)
			max_soFar = nums[i];

		if(max_endingHere < 0)
			max_endingHere = nums[i];
		else
			max_endingHere += nums[i];

		//if(max_endingHere != nums[i] && max_endingHere > max_soFar)
		if(max_endingHere > max_soFar)
			max_soFar = max_endingHere;
	}
	return max_soFar;

}


int main()
{
    cout << "Hi Hemu" << endl;
    vector<int> v;
    v.push_back(-2);
    v.push_back(-1);
    v.push_back(-5);
    v.push_back(-7);

    cout << maxSubArray(v) << endl;

    cout << "La Fin";
    return 0;
}
