#include <iostream>
#include <map>
using namespace std;

int main()
{
	pair<char,int> p;
	map<char,int> m;

	string s = "My name is Himanshu";
	char c;
	for(unsigned int i=0; i<s.length();i++)
	{
		c=s[i];
		m[c]++;
	}

	cout << "# occurances of 'a' are: " << m['a'] << endl;

	for(auto it=m.begin(); it!=m.end();it++)
	{
		cout << it->first <<"-"<< it->second << endl;
	}

	cout << endl << "La Fin!";
	return 0;
}
