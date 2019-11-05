#include<stdio.h>
using namespace std;

void print_binary(int byte)
{
	printf("%d",(byte & 0x80)? 1:0);
	printf("%d",(byte & 0x40)? 1:0);
	printf("%d",(byte & 0x20)? 1:0);
	printf("%d",(byte & 0x10)? 1:0);
	printf("%d",(byte & 0x08)? 1:0);
	printf("%d",(byte & 0x04)? 1:0);
	printf("%d",(byte & 0x02)? 1:0);
	printf("%d",(byte & 0x01)? 1:0);

	printf("\n");
}

void fun_binary(int num)
{
	int reg;
	reg = 1<<7;
	print_binary(reg);
	reg |= num;
	print_binary(reg);
}

int main()
{
	int num = 10;
	//cout << num << endl;
	printf("%d\n",num);
	printf("%X\n",num);
	print_binary(num);
	fun_binary(num);

	//cout << endl << "La Fin";
	return 0;
}