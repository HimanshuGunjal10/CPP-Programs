#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	x = x^y;
	y = x^y;
	x = x^y;
}

int main()
{
	int n1 = -1;
	int n2 = 7;

	cout << n1 << " " << n2 << endl;
	swap(n1,n2);
	cout << n1 << " " << n2 << endl;

	cout << endl << "La Fin!";
	return 0;
}

