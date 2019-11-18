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

bool isPalindrome(string s)
{
	//condensed solution using isalnum and smart for loop
	
	int len = s.length();
	if (len < 2)
		return true;
	
	for(int i=0, j=len-1; i<j; i++, j--)
	{
		while(i<j && !isalnum(s[i]))
			i++;
		while(i<j && !isalnum(s[j]))
			j--;

		if(tolower(s[i])!=tolower(s[j]))
			return false;
	}
	return true;

	/*
	int len = s.length();
	if (len < 2)
		return true;

	int i=0, j=len-1;

	while(i<j)
	{
		while(i<j)
		{
			if((s[i] >= '0' && s[i] <= '9')
				|| (s[i] >= 'a' && s[i] <= 'z')
				|| (s[i] >= 'A' && s[i] <= 'Z'))
				break;
			else
				i++;
		}

		while(i<j)
		{
			if((s[j] >= '0' && s[j] <= '9')
					|| (s[j] >= 'a' && s[j] <= 'z')
					|| (s[j] >= 'A' && s[j] <= 'Z'))
				break;
			else
				j--;
		}

		if(tolower(s[i]) != tolower(s[j]))
			return false;
		else
		{
			i++; j--;
		}
	}
	return true;
	*/
}


int main()
{
	string s1 = "mal8aya 8laM";

	cout << s1 << endl;
	cout << isPalindrome(s1);

	cout << endl << "La Fin!!";
}

