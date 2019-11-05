#include <bitset>
#include <math.h>
#include <iostream>
using namespace std;

int onlySetBitPosition(int n)
{
	// 1st check if more than 1 bits are set. if yes, then return -1
	if(n & (n-1))
	{
		cout << "More than 1 bits are set" << endl;
		return -1;
	}
	if(n==0)
		return -1;
	return (log2(n));	//will trouble if n is 0 as will return log2(-1)

}

int main()
{
	int n = 0;

	cout << "n = " << n << ": " << bitset<32>(n) << endl;
	cout << "n-1= " << n-1 << ": " << bitset<32>(n-1) << endl;


	cout << "only set bit at position: " << onlySetBitPosition(n) << endl;


//	cout << "n = " << n << ": " << bitset<32>(n) << endl;
	cout << endl << "La Fin!";
	return 0;
}

