#include <iostream>
using namespace std;

int add1(int n)
{
	return -~n;
}

int main()
{
	int n = -1;
	cout << add1(n);
	cout << endl << "La Fin!";
	return 0;
}

