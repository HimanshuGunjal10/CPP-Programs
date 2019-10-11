#include <iostream>
using namespace std;

int findComplement(int num)
{
/*	int count = 0;
	int num_copy = num;
	while(num_copy>0)
	{
		count++;
		num_copy = num_copy>>1;
	}

	for(int i=0; i<count; i++)
	{
		if(num)
		num = num ^ (1<<i);
	}
	return num;
	*/

	//Give same time analysis though
	int count = 0;
	int i=0;
	int num_copy = num;
	while(num_copy>>i)
	{
		num = num ^ (1<<i);
		i++;
	}
	return num;
}


int main()
{
	cout << findComplement(5);

	cout << endl << "La Fin!";
	return 0;
}
