/*
Read data from a fixed memory address
*/

#include<stdio.h>
#include<stdint.h>

#define FLAG_ADDR 0xAABBCCDD;



int main()
{
	volatile uint32_t *ptr = (volatile uint32_t*)FLAG_ADDR;

	uint32_t read_data;

	read_data = *ptr;
	printf("%d", read_data);

	printf("La Fin!");
	return 0;
}
