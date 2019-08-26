#if 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int calculateSetBits1(int num)
{
	int count = 0;
	for(int i=0; i<32; i++)	//loop runs for 32 no matter what
	{
		if(num & (1<<i))
			count++;
	}
	return count;
}

int calculateSetBits2(int num)	//Efficient code
{
	int count = 0;
	while(num)
	{
		count += num & 1;
		num >>= 1;		// num >> 1 has no effect as no assignment so num = num >> 1
	}
	return count;
}

int main ()
{
	int num = 10;

	printf("Set Bits using calculateSetBits1: %d \n",calculateSetBits1(num));
	printf("Set Bits using calculateSetBits2: %d \n",calculateSetBits2(num));



	return 0;
}
#endif
