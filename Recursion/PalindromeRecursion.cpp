#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	//base case: if length is 0 or 1 then that is a palindrome in itself
	if(s.length() < 2)
		return true;
	char first, last;
	//store first and last
	//pass the string excluding first and last
	//hence substring position is 1 and end point is length-2
	first = s[0];
	last = s[s.length()-1];

	//recursive case with a shorter string
	if(first == last)
		return isPalindrome(s.substr(1,s.length()-2));	//substr(pos,len)
	else
		return false;

}

int main()
{
	string s = "malayalam";
	if(isPalindrome(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	printf("\nLa fin");
	return 0;
}
