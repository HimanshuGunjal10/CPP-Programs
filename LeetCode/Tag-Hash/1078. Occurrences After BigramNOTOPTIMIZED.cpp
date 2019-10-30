#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

{
	stringstream ss(text);
	string prev2,prev1,curr;
	vector<string> res;
	while(ss >> curr)
	{
		if(prev2 == first && prev1== second)
			res.push_back(curr);
		prev2 = prev1;
		prev1 = curr;
	}
	return res;
}
/*
vector<string> findOcurrences(string text, string first, string second)
{
	stringstream ss(text);
	string temp;
	vector<string> vec_str;
	while(ss >> temp)
		vec_str.push_back(temp);
	
	//why do ++it and then go reverse
	//just check on the 3rd word and keep saing the prev words
	//also no need to push into a vector! just work on temp
	vector<string> res;
	for(vector<string>::iterator it=vec_str.begin();it!=vec_str.end()-1;it++)
	{
		if(*it == first)
		{
			if(*(++it) == second)
			{
				if( ++it !=vec_str.end())
				{
					res.push_back(*it);
				}
				--it;
			}
			--it;
		}
	}
	return res;
}
*/


int main()
{
	string text = "hello there how are you";
	vector<string> res = findOcurrences(text,"are","me");

	for(string i : res)
		cout << i << " ";
	cout << endl;


	cout << endl << "La Fin!!";
}
