#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(string s)
{
	for(unsigned int i=0; i<s.length(); i++)
		cout << s[i];
	cout << endl;
}

void swap(string& s, int i, int j)
{
	char temp;
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

void reverse(string& s)
{
	int len = s.length();
	int j;
	for(int i=0; i<len/2; i++)
	{
		j = len-1-i;
		swap(s,i,j);
	}
}

void reverse_stack(string s)
{
	cout << "Reversing \""<< s << "\"using stack" << endl;
	stack<char> stk;
	int len = s.length();
	for(int i=0; i<len; i++)
		stk.push(s[i]);

	while(!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}
	cout << endl;
}

int main()
{
	string s = "abcdefgh";
	//string s = "abcdefghi";

	print(s);
	reverse(s);
	print(s);
	reverse_stack(s);
	print(s);

    cout << endl << "La Fin!";
    return 0;
}
