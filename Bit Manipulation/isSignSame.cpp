#include <bitset>		//ONLY IN C++
#include <iostream>
using namespace std;

bool isSignSame(int num1, int num2)
{
	if((num1 ^ num2) < 0)
		return false;
	else
		return true;
}

int main()
{
	int num1 = -75;
	int num2 = -25;

	cout << "This is how you print in binary" << endl;
	cout << "num1 in 32 bit binary is: " << bitset<32>(num1) << endl;

	cout << "isSignSame?: " << isSignSame(num1,num2);

	cout << endl << "La Fin!";
	return 0;
}

