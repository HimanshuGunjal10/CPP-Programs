
//There is no index out of bound checking in C, program compiles fine but may produce unexpected output when run. (there was C++)
	int arr[2];
	printf("%d ", arr[3]);

//It is not compiler error to initialize an array with more elements than specified size in C. (there was C++)
	int arr[2] = { 10, 20, 30, 40, 50 };

	printf("Address arr[%d] is %p\n", i, &arr[i]); //printed out element by element (unlike strings)

--
//Strings are defined as an array of characters.
//The difference between a character array and a string is the string is terminated with a special character ‘\0’.
// A character array initialized with double quoted string has last element as ‘\0’. (which is a string)

//Initialize a character array
	char a[] = "hello";
	char b[5] = "hello";
	char c[] = {'h','e','l','l','o'};
	char d[6] = {'h','e','l','l','o'};

// *** Unlike arrays we do not need to print a string, character by character.

	char str[] = "Geeks"; //stored as Geeks\0
	printf("%s",str);	//access specifier “%s” used to directly print and read strings.

	char read_str[2];	//array size is imp char a[]; throws error! but reading not limited to it. Reads till space or enter character
	scanf("%s",read_str);
	printf("%s",read_str);

	/*
	output:
	CamelCaseAndExceedArraySpace
	Hello world
	CamelCaseAndExceedArraySpace
	
	As str[] is a character array so using str without braces ‘[‘ and ‘]’ will give the base address of this string. 
	That’s why we have not used ‘&’ in this case as we are already providing the base address of the string to scanf.

	*/

	//Passing strings to a function

	void printStr(char str[])		//always pass size of array to functions
		{printf("%s",str);}			//note %s


----------------------------------
Errors: (output)

	..\array.cpp:7:6: error: initializer fails to determine size of 'a'	//missing size
  int a[] = 5;

  	..\array.cpp:7:13: error: array must be initialized with a brace-enclosed initializers//missing {}
  int a[2] = 5;

  //****Note: It is ok for character strings to keep size unspecified.	char c[] = "hello"; throws no error.

	..\array.cpp:10:34: error: too many initializers for 'char [3]'	//small size declared
  char d[3] = {'h','e','l','l','o'};

----------------------------------




--
/*
puts(str) vs printf("%s", str)	************************IMP
puts is better:
1.less expensive  2.  if the string has formatting characters like ‘%’, then printf() would give unexpected results

Note: puts() moves the cursor to next line ************************IMP
	  insted use: fputs(str, stdout);

*/
	char str[] = "Hello world";
	printf("%s \n", str);
	puts(str);
	fputs(str,stdout);							//*********************
	puts(str);

	/*
	output:
	Hello world 
	Hello world
	Hello worldHello world
	*/

--
//In C, it is possible to have array of all types except 1. void 2. function
	void arr[5]; //ERROR
	void *arr[5]; // NO error as it a void array pointer

//Passing arrays to functions
/*
Arrays are always passed as pointers. Hence, we also need to pass size of array to the function.
*/
//main
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
	unsigned int n = sizeof(arr)/sizeof(arr[0]); 	//size = (8*4)/4 = 8
	fun(arr);	//passing to a fn
	.
	.
	void fun(int arr[])
	{
		unsigned int n = sizeof(arr)/sizeof(arr[0]);	//size = 8/8 = 1 (8-size of a pointer)
	}
//Note: Hence we always pass size of the array as well while passing arrays to functions.
//Never use sizeof(arr[]) operator in a function since a pointer is passed and will not return the true size.

	void fun(int *arr, unsigned int n)
	{....}
//main
	int n = sizeof(arr);
	fun(arr,n);

--
//
	void fun(int arr[])
	//is same as
	void fun (int *arrptr)
--
//Compiler Error: variable-sized object may not be initialized
	int M=2;
	int arr[M];	//no error
	int arr[M]={4};	//error ... // Trying to initialize all values as 0

--
//https://www.geeksforgeeks.org/are-array-members-deeply-copied/
//Shallow copy v/s Deep copy
	
	#include<cstring>

	struct strstruct
	{
		char str[5];
		//vs
		char *strptr;
	}
//main
	strstruct s1,s2;
	s1.strptr = new char[10];
	//or
	strcpy(s1.str,"Hello");
	s2 = s1;

	cout << s1.str << s2.str << endl;
	printf("%s %s",s1.str, s2.str);
//check link for difference

--
//'' v/s ""

	char arr[] = "geeks";	//size = 6 compiler puts '\0' in the end
	char arr[5] = "geeks";	//size = 6 w/o '\0' //not a compiler warning/error in C, but compilation error in C++ 
	char arr[]= {'g', 'e', 'e', 'k', 's'};	//size = 5 w/o '\0'

--
//MULTI-DIMENSIONAL ARRAY
//multidimensional arrays can have ONLY left most dimension as optional.

	int a[][][2] = { {{1, 2}, {3, 4}},  {{5, 6}, {7, 8}} }; //error
	int a[][2][2] = { {{1, 2}, {3, 4}},  {{5, 6}, {7, 8}} }; //works
	int a[][2] = {{1,2},{3,4}}; // Works

--
//char array v/s pointers to string literals
	char s[] = "himanshu" //creates a character array of size 9 ('\0' added) _ stored in stack (actually displayed size is 8 and not 9) 
	char *strptr = "geeksquiz"	//creates pointer to a string literal _ 'strptr' stored in stack but 'geeksquiz' stored in read only mem ***

	s[0] = 'j';	//valid...output= jeeksquiz
	strptr[0] = 'j';	//invalid _ segmentation error since code section is read only.

	s = "NewName"	//invalid
	strptr = "NewName"; 	//valid as its stored in read only mem

	puts(s);		//valid
	puts(strptr);	//valid //NewName

	s++; 	//invalid
	strptr++; 	//valid

	puts(++strptr);	//ewName //N is gone now


	/*
	Eclipse this
	char *sptr = "Hello";
	cout << sptr << " " << *sptr << " " << *++sptr << endl;
	puts(sptr);
	*/

// strptr is a pointer to a read only  memory location. So its better to declare it as:
	const char *strptr = "Himanshu";	//Removes this warning: deprecated conversion from string constant to ‘char*

--
//Issue with gets()

	char s[5];						//expected array size of 5
	printf("Enter a string: \n");
	fflush(stdout);					// :)
	gets(s);
	//printf("You entered: %s \n", s);
	puts(s); 	//Better to use puts() instead of printf();

/*
Output:
Enter a string: 
Himanshu
You entered: Himanshu 

-> So, no buffer overflow. gets() searches for endline charachter and reads everything till then. Issue!!!

*/

//Solution: use fgets()
	char s[MAX_LIMIT];
	printf("Enter a string: \n");
	fgets(s,MAX_LIMIT,stdin);
	puts(s);

/*Output:
HimanshuG
Enter a string: 
Hima

-> Reads only 4 since MAX_LIMIT = 5
*/


--
//SWAPPING STRINGS

//Note: The function just changes "local pointer variables" and the changes are not reflected outside the function.

//->code:

//function
void swap(char *p1, char *p2)
{
	char *temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

//main
	char *s1 = "Himanshu";
	char *s2 = "Gunjal";
	swap(s1,s2);
	printf("str1: %s \t str2: %s", s1, s2);

/*
Output:
str1: Himanshu 	 str2: Gunjal	//p1 and p2 changed and not s1,s2
*/

//Solution?
//Use a different version: - pass pointers to pointers

//function
void swap(char **p1, char **p2)	//check this passing pointers to pointers...how? pass address of ptrs in fn call
{
	char *temp;		//temp just has to be a pointer
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//main
	char *s1 = "Himanshu";
	char *s2 = "Gunjal";
	swap(&s1,&s2);			//passing address of pointers
	printf("str1: %s \t str2: %s", s1, s2);

/*
Output:
str1: Gunjal 	 str2: Himanshu
*/

//Note: Above function won't be applicable for char arrays, only char string literals

--









//TODO

	https://www.geeksforgeeks.org/function-pointer-in-c/
	https://www.geeksforgeeks.org/difference-pointer-array-c/
	https://www.geeksforgeeks.org/are-array-members-deeply-copied/
	https://www.geeksforgeeks.org/write-one-line-functions-for-strcat-and-strcmp/
	https://www.geeksforgeeks.org/swap-strings-in-c/
		https://icecube.wisc.edu/~dglo/c_class/vstorage.html
	

----
/*
//Check why this swap code is not working

#include "stdio.h"
int MAX_LIMIT = 5;

void swap(char **p1, char **p2)
{
	char *temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main()
{
	char a[MAX_LIMIT];
	char b[MAX_LIMIT];

	printf("Enter a:\t");
	fflush(stdout);
	fgets(a,MAX_LIMIT,stdin);

	fflush(stdin);

	printf("Enter b:\t");
	fflush(stdout);
	fgets(b,MAX_LIMIT,stdin);

	char *s1 = a;
	char *s2 = b;

	swap(&s1,&s2);

	return 0;
}
*/
----