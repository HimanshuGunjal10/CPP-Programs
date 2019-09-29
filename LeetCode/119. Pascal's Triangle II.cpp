#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex)
{
	//check 0 condition
	if(rowIndex == 0)
	{
		vector<int> vec0 = {0};
		return vec0;
	}

	vector<vector<int>> vec(rowIndex+1);

	int val;
	vec[0].push_back(1);
	for(int i=1; i<rowIndex+1; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j==0)
				vec[i].push_back(1);
			else if(j==i)
				vec[i].push_back(1);
			else
			{	//middle section
				val = vec[i-1][j-1] + vec[i-1][j];
				vec[i].push_back(val);
			}
		}
	}
	return vec[rowIndex];
}


void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
	{
			cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
    int numRows = 5;
    vector<int> res;
	res = getRow(numRows);
	print(res);
    cout << "La Fin";
    return 0;
}
