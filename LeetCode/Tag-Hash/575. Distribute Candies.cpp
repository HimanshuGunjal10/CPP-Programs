#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int distributeCandies(vector<int>& candies)
{
	unordered_set<int> s;
	unordered_map<int,int> m;

	for(int candy : candies)
		s.insert(candy);
	return min(s.size(),candies.size()/2);
}

int main()
{
	vector<int> candies = {1,1,2,3};

	cout << distributeCandies(candies);

	cout << endl << "La Fin!!";
}
