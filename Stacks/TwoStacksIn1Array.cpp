/*
 * Implementation of 2 stacks using a single array
 */

#include <iostream>
using namespace std;

class Stacks
{
	int* arr;
	int size;
	int top1,top2;

public:
	Stacks(int n);
	void push1(int val);
	void push2(int val);
	int pop1();
	int pop2();
	void print();
};

Stacks::Stacks(int n)
{
	size = n;
	arr = new int[size];
	top1 = -1;
	top2 = size;
}

void Stacks::push1(int val)
{
	//condition to check overlap
	if(top1<top2-1)
	{
		arr[++top1] = val;
	}
	else
	{
		cout << "overflow\n";
		exit(1);
		//return;
	}
}

void Stacks::push2(int val)
{
	//condition to check overlap
	if(top1<top2-1)
	{
		arr[--top2] = val;
	}
	else
	{
		cout << "overflow\n";
		exit(1);
		//return;
	}
}

int Stacks::pop1()
{
	if(top1<0)
	{
		cout << "Stack underflow\n";
		exit(1);
	}
	int ret = arr[top1];
	top1--;
	cout << "Popping1: " << ret << endl;
	return ret;
}

int Stacks::pop2()
{
	if(top2>=size)
	{
		cout << "Stack underflow\n";
		exit(1);
	}
	int ret = arr[top2];
	top2++;
	cout << "Popping2: " << ret << endl;
	return ret;
}

void Stacks::print()
{
	cout << "The two stacks array is : ";
	for(int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "Stack 1: ";
	for(int i=0; i<=top1;i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "Stack 2: ";
	for(int i=size-1; i>=top2;i--)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	Stacks arr_stack(10);
	arr_stack.push1(1);
	arr_stack.push1(2);
	arr_stack.push1(3);
	arr_stack.push1(4);
	arr_stack.push2(5);
	arr_stack.push2(6);
	arr_stack.push2(7);
	arr_stack.push2(8);

	arr_stack.print();

	arr_stack.pop1();
	arr_stack.pop2();

	arr_stack.print();

	cout << "La fin";
	return 0;
}
