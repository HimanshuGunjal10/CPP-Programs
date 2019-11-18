#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int fibo(int n)
{
	//int k = n;
	if(n==1 || n==2)
		return 1;

	return (fibo(n-1) + fibo(n-2));
}

int fibo_dp(int n, int arr[])
{
	if(n<2)
	{
		arr[n] = 1;
		return 1;
	}
	if(arr[n] != -1)
	{
		return arr[n];
	}
	else
	{
		return fibo_dp(n-1,arr)+fibo_dp(n-2,arr);
	}
}

int main()
{
	int num = 7;

	cout << fibo(num) << endl;
	int arr[10];
	memset(arr,-1,10*sizeof((arr[0])));
	for(int i=0; i<10; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << fibo_dp(num,arr);

	cout << "\nLa Fin!!";
}
