#include <iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;


void print(string s)
{
	for(unsigned int i=0; i<s.length(); i++)
		cout << s[i] << " ";
	cout << endl;
}

int getValue(char c)
{
	switch(c)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return -1;
	}
}

int romanToInt(string s)
{
	int len = s.length();
	if(len<1)
		return 0;
	if(len == 1)
		return getValue(s[0]);


	int val = getValue(s[0]);
	int res=0;
	int nextVal;
	for(unsigned int i=0; i<s.length()-1; i++)
	{
		nextVal = getValue(s[i+1]);

		if(val >= nextVal)
			res += val;
		else if(val < nextVal)
			res -= val;

		val = nextVal;
		if(i==s.length()-2)
			res += nextVal;
	}
	return res;
}

string intToRoman(int num)
{
	string res = "";

	string literals[] = {"M", "CM", "D","CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	int i=0;
	while(num>0 && i<13)
	{
		if(num - values[i] >= 0)
		{
			res.append(literals[i]);
			num -= values[i];
		}
		else
			i++;
	}
	return res;
}


int main()
{
	string s = "XXVII";

	cout << s << " : " << romanToInt(s);

	cout << endl;

	int num = 994;
	cout << num << " : " << intToRoman(num);

	cout << endl << "La Fin!";
	return 0;
}
