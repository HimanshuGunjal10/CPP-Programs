#include <iostream>
#include <vector>
#include<algorithm>
#include <set>
using namespace std;

void reverseString(vector<char>& s)
{
	int i = 0;
	int j = s.size()-1;

	while(i<j)
	{
		char temp = s[i];
		s[i++] = s[j];
		s[j--] = temp;
	}
}

void print_vec(vector<char>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
}

int main()
{
	vector<char> vec = {'h','e','l','l','o'};

	reverseString(vec);

	print_vec(vec);

	cout << endl << "La Fin!!";
}
