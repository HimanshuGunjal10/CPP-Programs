#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address)
{
	if(address.empty())
		return "";
	string res;
	for(int i=0; i<address.length();i++)
	{
		if(address[i] == '.')
			res.append("[.]");
		else
			res.push_back(address[i]);
	}
	return res;
}

int main()
{
	string s;// = "1.23.2.195";
	cout << defangIPaddr(s);

	cout << "\nLa Fin!!";
}
