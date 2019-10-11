#include <iostream>
using namespace std;

int hammingDistance(int x, int y)
{
	int count = 0;
	while(x>0 && y>0)
	{
		//if( ((x&1) == (y&1)) != 0 )
		if( ((x&1) ^ (y&1)))
			count++;
		x = x>>1;
		y = y>>1;
	}
	while(x>0)
	{
		if(x&1)
			count++;
		x = x>>1;
	}
	while(y>0)
	{
		if(y&1)
			count++;
		y = y>>1;
	}
	return count;
}

int main()
{
	int x = 4;
	int y = 14;

	printf("x: %X \n", x);
	printf("y: %X \n", y);

	cout << "hammingDistance: " << hammingDistance(x,y);

	cout << endl << "La Fin!";
	return 0;
}
