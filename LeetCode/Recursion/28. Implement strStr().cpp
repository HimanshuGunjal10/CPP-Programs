#include <iostream>
#include <vector>
#include<string>
#include <stack>
using namespace std;

int strStr(string haystack, string needle)
{
	//working but stack overflow for a big input!!!

	if(needle.length()==0)
		return 0;
	if(haystack.length()==0)
		return -1;

	int i=0,j=0,save_index=0;
	for(; i<haystack.length(); i++)
	{
		save_index=i;
		j=0;
		if(haystack[i] == needle[j])
		{
			save_index = i;
			while(i<haystack.length() && j<needle.length() && haystack[i] == needle[j])
			{
				i++;j++;
			}
			//notice the semicolon.
			//break when one condition hits true

			//1. both hay and needle terminated
			if(i==haystack.length() && j==needle.length())
				return save_index;
			else if(j==needle.length())
				return save_index;
			else if(i==haystack.length())
				return -1;
			else
				i = save_index;
		}
	}
	return -1;
}

/*
//working but stack overflow for a big input!!!

int recurseCheck(string haystack, string needle, int i, int j)
{
	//base case
	if(j == needle.length())
		return 1;
	return (haystack[i] == needle[j]) ? recurseCheck(haystack,needle,++i,++j) : -1;
}

int strStr(string haystack, string needle)
{
	if(needle.length()==0)
		return 0;
	if(haystack.length()==0)
		return -1;

	int i=0,j=0;
	for(; i<haystack.length(); i++)
	{
		j=0;
		if(haystack[i] == needle[j])
		{
			int res = recurseCheck(haystack,needle,i+1,j+1);
			if(res==1)
				return i;
		}
		else
		{
			if(++j == needle.length())
				return -1;
		}
	}
	if(i==haystack.length())
		return -1;
	return -1;
}

int main()
{
	string s1 = "mississippi";
	string s2 = "pi";

	cout << strStr(s1, s2);

	cout << endl << "La Fin!!";
}

*/