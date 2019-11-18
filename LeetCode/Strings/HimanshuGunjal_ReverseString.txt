#include <stdio.h>
#include <stdlib.h>

void string_reverse1(char* str)
{
	if(str == NULL)
		return;
	char* i = str;

	//int j = strlen(str)-1;
	//Not sure if this is allowed so taking the long route!
	char* j = str;

	while(*j != '\0')
		j++;
	j--;

	//reversing by swapping
	while(i<j)
	{
		char temp = *i;
		*i = *j;
		*j = temp;
		i++;
		j--;
	}
	puts(str);
}

char *string_reverse2(const char *string)
{
	//since its a constant string, I'm using dynamic memory allocation
	//Also, as I have implemented my own method to find length of the string in the above function
	//I will be using the built-in strlen() function.
	int len = strlen(string);
	char* reverse_string = (char*)malloc(sizeof(char)*(len));

	strcpy(reverse_string,string);

	for(int i=0, j=len-1; i<j; i++,j--)
	{
		char temp = reverse_string[i];
		reverse_string[i] = reverse_string[j];
		reverse_string[j] = temp;
	}
	return reverse_string;
}

int main()
{
	char str1[6] = {'H','e','l','l','o'};
	string_reverse1(str1);

	char* str2 = "World";
	puts(string_reverse2(str2));

	printf("\nThank You!!");
}

