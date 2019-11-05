#include <iostream>
#include <vector>
using namespace std;


void print_vec(vector<int>& vec)
{
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> vec = {-4,-1,0,3,10};
	print_vec(res);

	cout << endl << "La Fin!!";
}
