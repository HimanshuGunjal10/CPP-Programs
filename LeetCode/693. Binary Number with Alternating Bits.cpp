#include <iostream>
using namespace std;

bool hasAlternatingBits(int n)
{
	int num_copy = n;
	int i=0;
	while(num_copy>>i)
	{
		cout << (n & (1<<i))<< "\t" << ((n & (1<<(i+1))) > 0) << endl;
		if(((n & (1<<i))>0) ^ ((n & (1<<(i+1))) > 0))
		{
			i++;
			continue;
		}
		else
			return false;
	}
	return true;
}

int main()
{
	cout << hasAlternatingBitsShort(4);

	cout << endl << "La Fin!";
	return 0;
}
