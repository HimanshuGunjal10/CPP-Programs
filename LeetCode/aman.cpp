#include <iostream>
#include <unordered_map>
#include<math.h>
using namespace std;



int getInt(string num, unordered_map<char,int>& m)
{
	int n=0;
	int index;
	for(int i=num.length()-1; i>=0; i--)
	{
		index = (num.length()-1)-i;
		n += (pow(10,i))*(m[num[index]]);
	}
	//cout << "n " << n << endl;

	return n;
}

string getString(int num)
{
	unordered_map<int,char> m;
	for(int i=0; i<10; i++)
		m.insert({i,(i)});


	string res;
	int index;
	while(num>0)
	{
		index = num%10;
		num = num/10;
		char c = m[index];
		res += c;
	}
	return res;
}

string multiply(string num1, string num2)
{
	unordered_map<char,int> m;
	for(char ch='0'; ch<='9';ch++)
		m.insert({ch,(ch-48)});

	int n1 = getInt(num1,m);
	int n2 = getInt(num2,m);

	//cout << n1 << " " << n2 << endl;

	int res = n1*n2;

	string result = getString(res);

	return result;
}


int main()
{
	pair<char,int> p;
	unordered_map<char,int> m;


	string s1 = "123";
	string s2 = "45";

	string result = multiply(s1,s2);

	cout << result << endl;


	cout << endl << "La Fin!";
	return 0;
}
