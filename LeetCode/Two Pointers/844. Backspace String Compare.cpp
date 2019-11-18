#include <iostream>
#include <vector>
#include<algorithm>
#include <stack>
using namespace std;

bool backspaceCompare(string S, string T)
{
	//stack implementation

	stack<char> s1;
	stack<char> s2;
	//1. fill both stacks
	for(int i=0; i<S.length(); i++)
	{
		if(S[i]!='#')
			s1.push(S[i]);
		else if(S[i] == '#' && !s1.empty())
			s1.pop();
	}

	for(int i=0; i<T.length(); i++)
	{
		if(T[i]!='#')
			s2.push(T[i]);
		else if(T[i] == '#' && !s2.empty())
			s2.pop();
	}
	//2. check if equal
	if(s1.size() == s2.size())
	{
		while(!s1.empty() && s1.top() == s2.top())
		{
			s1.pop();
			s2.pop();
		}
		if(s1.empty())
			return true;
	}
	return false;
}

int main()
{
	string s1 = "#";
	string s2 = "##";

	cout << backspaceCompare(s1,s2);

	cout << endl << "La Fin!!";
}

