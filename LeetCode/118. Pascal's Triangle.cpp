#include <iostream>
#include <vector>
using namespace std;

//NOT USED DP

vector<vector<int>> generate(int numRows)
{
	//check 0 condition
	if(numRows == 0)
	{
		vector<vector<int>> vec = {{0}};
		return vec;
	}

	vector<vector<int>> vec(numRows);

	int val;
	vec[0].push_back(1);
	for(int i=1; i<numRows; i++)
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
	return vec;
}


void print(vector<vector<int>> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
	{
		for(unsigned int j=0; j<vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
    int numRows = 5;
    vector<vector<int>> res;
	res = generate(numRows);
	print(res);
    cout << "La Fin";
    return 0;
}
