#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int calcMaxWeight(string str, int p, int s, int t, int i, int n, int memo[])
{
	if(i>=n)
		return 0;
	if(memo[i] != -1)
		return memo[i];

	//assuming no pair
	int ans = s + calcMaxWeight(str,p,s,t,i+1,n,memo);

	//if it were a pair
	if(i+1 < n)
	{
		if(str[i] != str[i+1])
			ans =  max(ans, p+calcMaxWeight(str,p,s,t,i+2,n,memo));
		else
			ans = max(ans, (p+t)+calcMaxWeight(str,p,s,t,i+2,n,memo));
	}
	memo[i] = ans;
	return ans;
}

int getMaxWeight(string str, int p, int s, int t)
{
	int memo[str.length()];
	memset(memo,-1,sizeof(memo));
	return calcMaxWeight(str,p,s,t,0,str.length(),memo);
}

int main()
{
	string str = "AAAAABB";
	int p = 4, s = 1, t = -1;
	cout << getMaxWeight(str,p,s,t);

	cout << "\nLa Fin!!";
}
