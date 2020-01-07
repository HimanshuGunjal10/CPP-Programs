//2 ways of declaring a pointer:
	int *ptr = &num;    // A pointer variable that holds address of var. 

	int *ptr;
	ptr = &num;	//ALready declared that ptr is a pointer, so no need to put * here
--
	int val = 5;
	int *ptr= &val;

	/*output:
	&val: 000000000061FE4C 
	ptr:  000000000061FE4C 
	&ptr: 000000000061FE40 
	*/
// * gives value in the location
// & gives value of location
// &ptr gives address of ptr and not wher it is pointing to 
// .'. &val = ptr =/= &ptr
--
	ptr++;	//increments the address the ptr points to by 4 bytes

//	array name acts as a "pointer constant"

//Note:
	int val[3] = {'1','2','3'};	//outputs 49,50,51 (ASCII value)
	int val[3] = {1,2,3};	//outputs 1,2,3
	int *ptr = val;
	for (int i=0; i<3; i++)
			printf ("%d \t",*ptr++);

--
//2D arrays: arr[i][j] = *(*ptr+i)+j)

--
//Double pointers are pointers to pointers

	int val = 5;
	int *p1 = &val;
	int **p2 = &p1;		//note the & sign

	*p1  = 6;	//val = 6
	**p2 = 7;	//val = 7

--
//We pass arrays to functions as pointers to save MEMORY and TIME
--
// *& These operators cancel effect of each other when used one after another. 
	printf("%d", *&*&ptr); //its the same thing

--
//Imp concepts check the link-
https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/

//Note:
	int *fun()
	{
		int x = 5;
	//	v/s
	    static int x = 5;
	    return &x ;
	}
--

//VOID pointer
    int x= 5;
    void *ptr; 
    ptr = &x;  
    // (int*)ptr - does type casting of void  
    // *((int*)ptr) dereferences the typecasted
--
//NULL pointer
    int *ptr = NULL; 

// A null pointer stores a defined value, but one that is defined by the environment to not be a valid address for any member or object.
// NULL vs Void Pointer – Null pointer is a value, while void pointer is a type

--
//WILD pointer
    int *p;  /* wild pointer */ //not been initialized to anything

--
//Pointer to a function

	int * p = 5;	//*b/w int and p 
	int * foo(int); 	//foo is a fn that takes one arg as int and returns a pointer of typr int*
	// () takes precedence over * .'.  use ()
	int (*foo)(int)		// correct way to declare a fn pointer

--
/* Note:
a string literal initialization of a character array
o char array[] = “abc” sets the first four elements in array to ‘a’, ‘b’, ‘c’, and ‘\0’
o char *pointer = “abc” sets pointer to the address of the “abc” string (which may be stored in read-only memory and thus unchangeable)*/

--
int a[3];
int *p = NULL;

p=a;	//	Legal
a=p;	//	Illegal

p++;	//	Legal
a++;	//	Illegal

--
VOID pointer
//A void pointer can hold address of any type and can be typcasted to any type.
	void *ptr;
	int a=5;
	char c='x';
	ptr=&a;
	ptr=&b;	//	it can hold both. But cant do any arithemtic on it. If so then cast int on it.

--
malloc() and calloc() return void * type and this allows these functions to be used to allocate memory of any data type (just because of void *)

	int main(void) 
{ 
    // Note that malloc() returns void * which can be  
    // typecasted to any type like int *, char *, .. 
    int *x = (int*)malloc(sizeof(int) * n); 
} 

--
//void pointers cannot be dereferenced
    int a = 10; 
    void *ptr = &a; 
    printf("%d", *ptr);     // WON'T COMPILE
    //so instead do this
    printf("%d", *(int *)ptr); 

    *(int *)ptr // void pointer dereferencing

--
/*NULL pointer: NULL expands to an implementation-defined null pointer constant 
which is defined in many header files such as “stdio.h”, “stddef.h”, “stdlib.h” etc.*/
	if(ptr != NULL) /*is same as*/ if(ptr);

--

/*
"Near pointer" is used to store 16 bit addresses means within current segment on a 16 bit machine.
"Far pointer" is typically 32 bit that can access memory outside current segment.
compiler allocates a segment register to store segment address, then another register to store offset within current segment.
"Huge pointer" same as far pointer but in far pointer, the segment part cannot be modified, but in Huge it can be
*/

--
int* restrict ptr;
//type qualifier for pointers
//it tells the compiler that ptr is the only way to access the object pointed by it and compiler doesn’t need to add any additional checks.

--
const
//const keyword applies to whatever is immediately to its left. If there is nothing to its left, it applies to whatever is immediately to its right.

1.
const char * p; /*is same as*/ char const *p;

char a = 'A';
char b = 'B';
const char * p = &a;

*p = &b; //This would be invalid. Cant change the value at p, but can change the address p points to
p = &b; //this would be VALID

2.
char *const p;
//You cannot change the pointer p, but can change the value pointed by ptr.
*p = &b; //valid
p = &b; //invalid

3.
const char* const p;
//This is a constant pointer to constant character. You can neither change the value pointed by ptr nor the pointer ptr. 

--
Not Done:

Pointers and arrays: https://www.geeksforgeeks.org/pointer-array-array-pointer/
Linked lists : https://www.geeksforgeeks.org/generic-linked-list-in-c-2/