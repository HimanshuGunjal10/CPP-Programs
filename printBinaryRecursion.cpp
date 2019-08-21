#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void printBinary(int num)
{
	if(num<0)
		cout << "Negative number found" << endl;

	//base case
	if(num < 2)
		cout << num;
	//recursive case
	else
	{
		printBinary(num/2);
		cout << num%2;
	}
}

int main()
{
	int num = 7;
	printBinary(num);

	printf("\nLa fin");
	return 0;
}


/*
 * 	1st try: correct, but not optimised
 * 	//base case
	if(num == 1)
		cout << "1";
	else if (num == 2)
		cout << "10";
 */
