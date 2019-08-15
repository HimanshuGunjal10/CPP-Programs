//https://www.youtube.com/watch?v=g-1Cn3ccwXY

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

bool func(int x, int y)
{
	return x>y;
}

void print(set<int>&s)
{
	set<int>::iterator it;
	for(it=s.begin(); it !=s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	//Note:
	//If you use push_back to insert elements in a vector, you will have to again sort the vector.
	//So, SETS are better
	//inserts in a sorted order in O(logN) time


	set<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(-1);
	s.insert(-10);
	s.insert(9);
	s.insert(15);

	//sorted output automatically as elements are stored in sorted order in sets
	print(s);

	//to find a value
	//since it is already sorted no need to pass the begin and end here (unlike vectors)

	set<int>::iterator it = s.find(-10);
	//returns the iterator if found or the iterator s.end() if not found

	if(it == s.end())
		cout << "Element not found\n";
	else
		cout << "Element found: " << *it << " at location" << " not possible (use STL distance) for sets" << endl;
	//drawback can't do it2-it1 like in vectors to get count or index

	return 0;
}
