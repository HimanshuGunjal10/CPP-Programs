#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> commonChars(vector<string>& A)
{
	vector<int> vec(26);
	for(char ch : A[0])
		++vec[ch-'a'];

	for(string s : A)
	{
		vector<int> temp_vec(26);
		for(char ch : s)
			++temp_vec[ch-'a'];

		for(int i=0; i<26; i++)
		{
			if(vec[i]>0 && temp_vec[i]<=0)
				vec[i] = 0;
			vec[i] = min(vec[i],temp_vec[i]);
		}
	}
	vector<string> res;
	for(int i=0; i<26; i++)
	{
		if(vec[i]<=0)
			continue;
		string s = string(1,i+'a');
		res.insert(res.end(),vec[i],s);
	}
	return res;
}

int main()
{
	vector<string> input = {"cool","lock","cook"};
	vector<string> res = commonChars(input);

	for(auto s : res)
		cout << s << " ";
	cout << endl;


	cout << endl << "La Fin!!";
}
