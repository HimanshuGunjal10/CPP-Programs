#if 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char str1[], int size1, char str2[], int size2)
{
	if(size1 != size2)
		return false;

	int chararray[128];
	memset(chararray,0,sizeof(chararray));

	for(int i=0; i<size1; i++)
		chararray[str1[i]-'a']++;

	for(int i=0; i<size2; i++)
	{
		if(--chararray[str2[i]-'a'] < 0)
			return false;
	}
	return true;



}

int main()
{

	char str1[] = "pat";
	char str2[] = "tap";

	int size1 = sizeof(str1)/sizeof(str1[0]);
	int size2 = sizeof(str2)/sizeof(str2[0]);

	bool res = is_palindrome(str1,size1,str2,size2);

	printf("Res: %d",res);


	printf("\nLa Fin!!");
}
#endif
