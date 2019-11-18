#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string str)
{
	if(str.length() == 0)
		return str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i] = str[i] + ('a'-'A');
	}
	return str;
}

int main()
{
	string s = "Hello";
	cout << toLowerCase(s);

	cout << "\nLa Fin!!";
}
