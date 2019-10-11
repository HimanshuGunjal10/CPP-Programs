//https://www.youtube.com/watch?v=g-1Cn3ccwXY

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool func(int x, int y)
{
	return x>y;
}

void print(vector<int>&vec)
{
	vector<int>::iterator it;
	for(it=vec.begin(); it !=vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> vec = {12,2,13,50};

	print(vec);

	//sort O(Nlog(N))
	sort(vec.begin(),vec.end());
	print(vec);

	//binary search after sorting O(log(N))
	bool flag1 = binary_search(vec.begin(), vec.end(), 50);
	cout << flag1 << endl;

	bool flag2 = binary_search(vec.begin(), vec.end(), 100);
	cout << flag2 << endl;

	vec.push_back(100);
	vec.push_back(100);
	vec.push_back(100);
	vec.push_back(113);
	vec.push_back(129);

	//finds occurrence of 1st of smallest and immediate greater than element
	vector<int>::iterator it1 = lower_bound(vec.begin(), vec.end(), 100);
	vector<int>::iterator it2 = upper_bound(vec.begin(), vec.end(), 100);

	cout << *it1 << " " << *it2 << endl;

	// get the no. of occurrences of an element
	cout << it2-it1 << endl;	//not the vlaue but the it count

	//sort in reverse order
	// need to pass another parameter: function which returns a bool value of > comparison
	sort(vec.begin(),vec.end(),func);
	print(vec);

	//note sort cannot be used for lists as list has birirectional pointers so l.begin() and l.end() do not work.
	//note: sort algorith requires random access operators(v.begin() and v.end() for e.g.)

	make_heap(vec.begin(),vec.end());
	print(vec);


	return 0;
}
