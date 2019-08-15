/*
 * Program to check if parehtheiss are balanced using Stack class
 */

#include <iostream>
#include<stack>
#include<string>
using namespace std;

bool checkIfParanthesisAreBalanced(string str)
{
	stack<char> s;	//imp: type is required

	for(unsigned int i=0; i<str.length(); i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s.push(str[i]);
			continue;		//***IMP
		}

		if(s.empty())
		{
			cout << "No parenthesis found\n" << endl;
			break; //exit(1);
		}

		char c = str[i];
		char top = s.top();

		switch(c)
		{
		case ')':
			if(top == '{' || top == '[')
			{
				cout << "Mismatch at )\n" << endl;
				return false;
			}
			s.pop();		//***imp
			break;

		case '}':
			if(top == '(' || top == '[')
			{
				cout << "Mismatch at }\n" << endl;
				return false;
			}
			s.pop();
			break;

		case ']':
			if(top == '{' || top == '(')
			{
				cout << "Mismatch at ]\n" << endl;
				return false;
			}
			s.pop();
			break;
		}

	}
	return true;
}

int main()
{
	string str = "[{()}]";
	bool flag = checkIfParanthesisAreBalanced(str);

	if(flag)
		cout << "Balanced\n";
	else
		cout << "Not balanced\n";

	cout << "La fin";
	return 0;
}
