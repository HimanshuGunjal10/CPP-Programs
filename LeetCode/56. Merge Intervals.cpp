#include <iostream>
#include<vector>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;

/*
void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
*/

void print2Dvec(vector<vector<int>> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
	{
		for(unsigned int j=0; j<vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	vector<vector<int>> res;


	set<pair<int,int>> s;
	pair<int,int> p;

	for(unsigned int i=0; i<intervals.size(); i++)
	{
		p = make_pair(intervals[i][0],intervals[i][1]);
		s.insert(p);
	}

	set<pair<int,int>>::iterator curr;
	set<pair<int,int>>::iterator prev;


	for(curr = s.begin(); curr!= s.end(); curr++)
	{
		if(curr == s.begin())
		{
			prev = curr;
			continue;
		}

		if(curr->first == prev->first)
			s.erase(prev);

		if(curr->second == prev->second)
			s.erase(curr);

		else if(curr->first < prev->second)
		{
			int asFirst = (prev->first < curr->first)? prev->first : curr->first;
			int asSecond = (prev->second > curr->second)? prev->second : curr->second;
			s.erase(prev);
			set<pair<int,int>>::iterator del_this = curr;
			s.erase(del_this);
			s.insert(make_pair(asFirst,asSecond));
		}
	}
	for(curr = s.begin(); curr!= s.end(); curr++)
		res.push_back({curr->first, curr->second});

	return res;
}

int main()
{
	vector<vector<int>> vec = {{1,4},{2,3}};
	print2Dvec(vec);

	vector<vector<int>> res = merge(vec);
	print2Dvec(res);

	cout << endl << "La Fin!";
	return 0;
}
