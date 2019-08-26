/*
 * Implementation of stack using LL
 * Time complexity O(n)
 */

#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
public:				//use public if not accessing using objects
	int top;
	unsigned capacity;
	char* array;
};


//utility fn: isFull
bool isFull (Stack* stack)
{
	return (stack->top == (stack->capacity-1));
}

//utility fn: isEmpty
bool isEmpty (Stack* stack)
{
	return (stack->top == -1);
}


Stack* createStack(int capacity)
{
	Stack* temp = new Stack;
	temp->top = -1;
	temp->capacity = capacity;
	temp->array = new char[sizeof(char)*capacity];
	return temp;
}

void push(Stack* stack, int val)
{
	if(isFull(stack))
		return;
	stack->array[++stack->top] = val;
}

char pop(Stack* stack)
{
	if(isEmpty(stack))
		return -1;		//'.' function has a return type of char, only return; will throw an eror
	char ret = stack->array[stack->top];
	stack->top--;
	return ret;
}

void reverse(char str[])
{
	int capacity = strlen(str);
	Stack* stack = createStack(capacity);

	//create the stack and push the string in it
	for(int i=0; i<capacity; i++)
	{
		push(stack,str[i]);
	}

	//pop the stack and store to get the reverse string
	for(int i=0; i<capacity; i++)
	{
		str[i] = pop(stack);
	}
}

int main()
{
	char str[] = "Himanshu";
	cout << str << endl;
	reverse(str);
	cout << str << endl;
	cout << "La fin";
	return 0;
}
