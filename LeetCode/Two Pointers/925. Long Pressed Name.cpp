#include <iostream>
#include <vector>
#include<algorithm>
#include <stack>
using namespace std;

bool isLongPressedName(string name, string typed)
{
	int i=0;
	int j=0;

	while(j<typed.length())
	{
		if(i<name.length() && name[i] == typed[j])
		{
			i++; j++;
		}
		else
		{
			if(name[i-1] != typed[j])
				return false;
			while(name[i-1] == typed[j])
				j++;
		}
	}
	if(i == name.length() && j == typed.length())
		return true;
	else
		return false;

}

int main()
{
	string s1 = "h";
	string s2 = "h";

	cout << isLongPressedName(s1,s2);

	cout << endl << "La Fin!!";
}

