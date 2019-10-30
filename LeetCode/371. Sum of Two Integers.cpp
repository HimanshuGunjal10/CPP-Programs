#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int getSum(int a, int b)
{
	int result = 0;
	int carry = 0;

	for(int i=0; i<32; i++)
	{
		result |= ( ( (a>>i)&1 ) ^ ( (b>>i)&1 ) ^ carry ) << i;

		if( ( ( (a>>i)&1 ) & ( (b>>i)&1 )) == 1 ||
				((( (a>>i)&1 ) & carry )) == 1 || ((( (b>>i)&1 ) & carry )) == 1 )
			carry = 1;
		else
			carry = 0;
	}
	return result;
}

int main()
{
	cout << getSum(5,3);

	cout << endl << "La Fin!";
	return 0;
}
