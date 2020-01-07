#if 1
/*
Note:
Arrays are passed by reference always. Vectors are not.
So always pass them by reference. (use &)
void foo (vector<int>& myVec);
void foo (const vector<int>& myVec); //for read only vectors

*/

//executable code with commands

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void printVec (const vector<int>& b)			//only change here. Fn call will be the same. Also, use const since read only
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

void printRevVec (const vector<int>& b)			// advisable to pass it like this. Check advanced lessons
{
	if(b.empty())
		cout << "Vector is empty \n";
	else
	{
		for(unsigned int i=b.size(); i>0; i--)	//b.size() to get the last index
			cout << b.at(i-1) << " ";			// do i-1 here and not b.size()-1 to get the 1st index
		cout << endl;
	}
}

int main()
{
	vector <int> v(3);	//check output. 1st 3 elements are 000
	int input;

	cout << "Enter elements, -1 to terminate input" << endl;
	cin >> input;

	while(input != -1)
	{
		v.push_back(input);
		cin >> input;	
	}

	printVec(v);
	printRevVec(v);


	return 0;
}
#endif
