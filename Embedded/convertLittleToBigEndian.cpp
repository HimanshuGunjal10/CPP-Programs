/*
 * Convert big to small endian
 */

#include <iostream>
using namespace std;

uint32_t convertToBigEndian(uint32_t &num)
{
	return ( ((num >> 24) & 0x000000FF)
			| ((num >> 8) & 0x0000FF00)
			| ((num << 8) & 0x00FF0000)
			| ((num << 24) & 0xFF000000));
}

int main()
{
	uint32_t num = 0xAABBCCDD;
	printf("printf 0x%X \n", num);

	uint32_t revNum = convertToBigEndian(num);
	printf("printf 0x%X \n", revNum);


	//printBinary(num);

	printf("\nLa fin");
	return 0;
}


--------

uint32_t convertToBigEndian(uint32_t &num)	//or vice versa
{
	return ( ((num >> 24) & 0x000000FF)
			| ((num >> 8) & 0x0000FF00)
			| ((num << 8) & 0x00FF0000)
			| ((num << 24) & 0xFF000000) );
}