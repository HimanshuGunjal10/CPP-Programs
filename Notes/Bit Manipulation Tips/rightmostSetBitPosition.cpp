#include <bitset>
#include <iostream>
using namespace std;

int rightmostSetBitPosition(int n)
{
	//if odd return 1;
	if(n & 1)
		return 1;

//	n = n ^ (n-1);

	int i = 1;
	while((n&1) == 0)
	{
		i++;
		n >>= 1;
	}
	return i;
}

int main()
{
	int n = 8;

	cout << "n = " << n << ": " << bitset<32>(n) << endl;

	cout << "1 found at position: " << rightmostSetBitPosition(n) << endl;


//	cout << "n = " << n << ": " << bitset<32>(n) << endl;
	cout << endl << "La Fin!";
	return 0;
}

