//executable code with commands

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void printVec (vector<int> b)			//not advisable to pass it like this. Check advanced lessons
{
	if(b.empty())
		cout << "Vector is empty \n";
	else
	{
		for(unsigned int i=0; i<b.size(); i++)	//since using a function that returns size , use unsigned int
			cout << b.at(i) << " ";				// or b[i]
		cout << endl;
	}
}

int main()
{
	vector <int> v(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	v.push_back(4);				//adds an element AND resizes it
	v.push_back(5);

	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v.at(2) << endl;

	printVec(v);

	v.insert(v.begin(),6);		//always use v.begin() when using insert
	printVec(v);

	v.insert(v.begin()+3,7);	// +3 to insert at that index (i.e 4th element will be 7)
	printVec(v);

	v.erase(v.begin()+4);		//remove an element
	printVec(v);

	v.pop_back();				//removes last element
	printVec(v);

	if(v.empty())				//returns a bool
		cout << "Empty \n";
	else
		cout << "Not empty \n";

	v.clear();					//clears all elements
	printVec(v);

	//Note:
	vector<int> vec2(3,10) //10 10 10

	return 0;
}
