#include <bitset>
#include <math.h>
#include <iostream>
using namespace std;

void convertToAllUppercase(string &s)
{
	for(int i=0; i<s.length(); i++)
	{
		if(s[i] >= 'a' && s[i] <= 'z')
			//s[i] = char((int)s[i] - 32);	//correct but no need
			s[i] = s[i]-32;
	}
}

int findPositionInAZ(char c)
{
	return int(c & 31);
}

int findAbsoluteWithoutBranching(int n)
{
	int mask;
	if(n>=0)
		mask = 0;
	else
		mask = -1;
	return (n + mask) ^ mask;
	//i.e. subtract 1 and xor with -1(to flip bits)
	//reverse step of finding compliment

	//equivalent in 1 line as :  return (x + (x >> 31)) ^ (x >> 31);
}


int main()
{
	string s = "HimansHu";
	convertToAllUppercase(s);
	cout << s;
	cout << endl << "---" << endl;

	cout << findPositionInAZ('b');
	cout << endl << "---" << endl;

	cout << findAbsoluteWithoutBranching(-7);
	cout << endl << "---" << endl;


	cout << endl << "La Fin!";
	return 0;
}

