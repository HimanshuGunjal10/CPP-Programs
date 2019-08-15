/*
 * Program to print the next greater element.
 * if not print -1 for the element
 * Using normal case, O(n^2)
 * Using stack O(n) or O(kn) for worst case
 * Stack is used to hold all elements who didn't have a greater value to the right YET.
 */

#include <iostream>
#include<stack>
#include<string>
using namespace std;

void printNextGreater(int arr[], int size)
{
	stack<int> s;
	int next;
	//push the 1st element
	s.push(arr[0]);

	for(int i=1; i<size; i++)	//i=1
	{
		if(s.empty())
		{
			s.push(arr[i]);
			continue;			//important step,
								//If empty, push in stack and check the next element i.e i+1, so continue
		}
		next = arr[i];

		//check next with all elements in the stack
		while(!s.empty() && s.top() < next)
		{
			cout << s.top() << "-->" << next << endl;
			s.pop();
		}

		//if not greater, then put that element in stack as well
		s.push(arr[i]);

	}
	//Now, all elements remaining in the stack did not have an greater value on the right.
	//So print all of them as -1
	while(!s.empty())
	{
		cout << s.top() << "--> -1" <<endl;
		s.pop();
	}
}

int main()
{
	int arr[] = {1,3,7,4,8,5,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	printNextGreater(arr,size);

	cout << "La fin";
	return 0;
}
