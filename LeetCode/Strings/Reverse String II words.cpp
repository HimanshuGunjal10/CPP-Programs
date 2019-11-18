#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

string rev(string s)
{
	if(s.length() < 2)
		return s;
	int i=0, j=s.length()-1;
	while(i<j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;j--;
	}
	return s;
}

string reverseWords(string s)
{
	if(s.length() < 2)
		return s;

	stringstream ss(s);
	string part;
	string res;
	while(ss>>part)
	{
		res += rev(part);
		res += " ";
	}
	res = res.substr(0,res.length()-1);
	return res;
}


int main()
{
	string s = "Let's take LeetCode contest";
	cout << reverseWords(s);

	cout << "\nLa Fin!!";
}
