#include <iostream>
#include <map>
using namespace std;

int main()
{
	pair<char,int> p;
	map<char,int> m;

	for(char c='a'; c<='z'; c++)
	{
		p.first = c;
		p.second = (int)c;
		m.insert(p);
	}

	map<char,int> :: iterator it;

	for(it=m.begin();it!=m.end();it++)
	{
		cout<<(*it).first << " " << it->second << endl;
	}

	cout << endl << "La Fin!";
	return 0;
}
