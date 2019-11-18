#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s)
{
	int res=0, count=0;
	for(int i=0; i<s.length();i++)
	{
		if(s[i] == 'L')
			count++;
		else
			count--;
		if(count==0)
			res++;
	}
	return res;
}

int main()
{
	string s = "RLRRRLLRLL";
	cout << balancedStringSplit(s);

	cout << "\nLa Fin!!";
}
