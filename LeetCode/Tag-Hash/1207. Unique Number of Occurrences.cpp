#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr)
{
	unordered_map<int,int> m;
	unordered_set<int> s;

	for(int i=0; i<arr.size(); i++)
	{
		m[arr[i]]++;
	}
	for(unordered_map<int,int>::iterator it =m.begin(); it!=m.end(); it++)
	{
		s.insert(it->second);
	}
	if(m.size() == s.size())
		return true;
	else
		return false;

}


int main()
{
	vector<int> vec = {1,2,3,4,2,3,3,4,4,4};

	cout << uniqueOccurrences(vec) << endl;

	cout << endl << "La Fin!!";
}
