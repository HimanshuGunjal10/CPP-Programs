#include <iostream>
using namespace std;

int fact(int n)
{
	//base case
	if(n==2)
		return 2;
	//sub cases
	return n*(fact(n-1));
}

int recurse_fibo(int n, int term1, int term2)//prev
{
	cout << term1 << " ";
	//base case
	if(n == 0)
	{
		return term1+term2;
	}
	//sub cases
	recurse_fibo(n-1,term2, term1+term2);

}

void fibo(int n)
{
	recurse_fibo(n,0,1);
}

int main()
{
	int n = 10;

	cout << "factorial: "  << fact(n) << endl;
	cout << "fibonacci: ";
	fibo(n);
	cout << endl;

	cout << endl << "La Fin!!";
}

