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

bool isPalindrome(string s, int i, int j)
{
	for(;i<j; i++,j--)
		if(s[i]!=s[j])
			return false;
	return true;
}

bool validPalindrome(string s)
{
	if(s.length()<2)
		return true;

	//given only chars b/w a-z. so simplified input
	for(int i=0, j=s.length()-1; i<j; i++, j--)
	{
		if(s[i] != s[j])
		{
			//check if the substring starting from i+1 to j OR i to j-1 is a palindrome
			return (isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1));
		}
	}
	return true;

}


int main()
{
	string s1 = "m8alay88alam";

	cout << s1 << endl;
	cout << validPalindrome(s1);

	cout << endl << "La Fin!!";
}

