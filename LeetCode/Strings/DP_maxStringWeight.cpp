#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int calcMaxWeight(string s, int i, int n, int memo[])
{
	if(i>=n)
		return 0;
	if(memo[i] != -1)
		return memo[i];

	//assuming no pair
	int ans = 1 + calcMaxWeight(s,i+1,n,memo);

	//if it were a pair
	if(i+1 < n)
	{
		if(s[i] != s[i+1])
			ans =  max(ans, 4+calcMaxWeight(s,i+2,n,memo));
		else
			ans = max(ans, 3+calcMaxWeight(s,i+2,n,memo));
	}
	memo[i] = ans;
	return ans;
}

int getMaxWeight(string s)
{
	int memo[s.length()];
	memset(memo,-1,sizeof(memo));
	return calcMaxWeight(s,0,s.length(),memo);
}

int main()
{
	string s = "AAAAABB";
	cout << getMaxWeight(s);

	cout << "\nLa Fin!!";
}
