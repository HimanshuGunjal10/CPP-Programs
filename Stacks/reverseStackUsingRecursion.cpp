/*
 * Program to reverse a stack using recursion.
 */

#include <iostream>
#include<stack>
#include<string>
using namespace std;

stack<int> s;

void print(stack<int> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void insertAtBottom(int x)
{
	//base case
	if(s.empty())
	{
		s.push(x);
	}
	else							//imp step
	{
		int y = s.top();
		s.pop();
		insertAtBottom(x);			//push x
		s.push(y);					//push y
	}
}
void reverse()
{
	//base case: return if empty
	if(!s.empty())
	{
		int x = s.top();
		s.pop();
		reverse();
		insertAtBottom(x);
	}
}

int main()
{
	int arr[] = {1,3,7,4,8,5,9};
	int size = sizeof(arr)/sizeof(arr[0]);

	//pushing values in stack
	for(int i=0; i<size; i++)
		s.push(arr[i]);

	print(s);
	reverse();
	print(s);

	cout << "La fin";
	return 0;
}
