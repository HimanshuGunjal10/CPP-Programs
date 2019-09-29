#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
	int low = 0;
	int high = numbers.size()-1;
	int sum;

	while(low<high)
	{
		sum = numbers[low] + numbers[high];

		if(sum == target)
			return {low+1,high+1};

		else if(sum < target)
			low++;
		
		else if(sum > target)
			high--;
	}
	return {-1,-1};
}


void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(24);
    v.push_back(50);
    v.push_back(79);
    v.push_back(88);
    v.push_back(150);
    v.push_back(345);


    print(v);

    int target = 200;
    vector<int> res = twoSum(v,target);
    print(res);

    cout << "La Fin";
    return 0;
}
