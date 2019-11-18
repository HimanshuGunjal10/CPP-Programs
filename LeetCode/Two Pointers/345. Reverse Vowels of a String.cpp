#include <iostream>
#include <vector>
#include<string>
#include <stack>
using namespace std;

void swap(string &s, int i, int j)
{
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

string reverseVowels(string s)
{
	int i=0, j=s.length()-1;
	while(i<j)
	{
		while(i<j && i<s.length() &&
				s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' &&
				s[i]!='A' && s[i]!='E' && s[i]!='I' && s[i]!='O' && s[i]!='U')
			i++;
		while(i<j && j>=0 &&
				s[j]!='a' && s[j]!='e' && s[j]!='i' && s[j]!='o' && s[j]!='u' &&
				s[j]!='A' && s[j]!='E' && s[j]!='I' && s[j]!='O' && s[j]!='U')
			j--;
		swap(s,i,j);
		i++; j--;
	}
	return s;
}

int main()
{
	string s1 = "ai";

	cout << s1 << endl;
	cout << reverseVowels(s1);

	cout << endl << "La Fin!!";
}

