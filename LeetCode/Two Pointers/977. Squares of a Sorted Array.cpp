#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;

vector<int> sortedSquares(vector<int>& A)
{

    /*
    O(NlogN) since using sort function
	for(int i=0; i<A.size();i++)
	{
		A[i] = A[i]*A[i];
	}
	sort(A.begin(),A.end());
	return A;
	}
    */
                /////////////////////////////////////

    //O(N) implementation. lengthy code but better t-c

	int i = 0;
	vector<int> res;

	//corner case: if all negative values.
	while(i<A.size() && A[i]<0)
		i++;
	//now i points to the first positive value;

	//corner case: if all negative values
	int j=0;
	if(i >= A.size())
		j = A.size()-1;
	else
		j= i-1;
	int i2 = 0;
	int j2 = 0;
	while(i<A.size() && j>=0)
	{
		i2 = A[i]*A[i];
		j2 = A[j]*A[j];

		if(i2<j2)
		{
			res.push_back(i2);
			i++;
		}
		else
		{
			res.push_back(j2);
			j--;
		}
	}
	while(i<A.size())
	{
		res.push_back(A[i]*A[i]);
		i++;
	}
	while(j>=0)
	{
		res.push_back(A[j]*A[j]);
		j--;
	}

	return res;

}

void print_vec(vector<int>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = {-4,-1,0,3,10};
	vector<int> res = sortedSquares(vec);

	print_vec(res);

	cout << endl << "La Fin!!";
}
