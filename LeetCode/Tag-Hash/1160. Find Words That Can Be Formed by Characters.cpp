#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countCharacters(vector<string>& words, string chars)
{
	vector<int>arr(26);
	int total_count = 0;
	for(auto ch : chars)
		arr[ch-'a']++;

	for(auto str : words)
	{
		bool match = true;
		vector<int> temp_arr;
		temp_arr = arr;
		for(char ch : str)
		{
			if(--temp_arr[ch-'a'] < 0)
			{
				match = false;
				break;
			}
		}
		if(match)
			total_count += str.length();
	}
	return total_count;

}


int main()
{
	vector<string> vec = {"cat","bt","hat","tree"};
	string chars = "atach";
	cout << countCharacters(vec,chars);


	cout << endl << "La Fin!!";
}
