#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char* pcBuffer = NULL;

	/* Initial memory allocation */
	pcBuffer =(char*) malloc(8);		//.c file doesnt need to typecast malloc as (char*)
	//pcBuffer = malloc(8);				//i.e. this works for .c files (for malloc calloc and realloc)

	strcpy(pcBuffer, "article");
	printf("pcBuffer = %s\n", pcBuffer);

	/* Reallocating memory */
	pcBuffer = (char*)realloc(pcBuffer, 15);

	strcat(pcBuffer, "world");
	printf("pcBuffer = %s\n", pcBuffer);

	//free the allocated memory
	free(pcBuffer);

	return 0;
}
#endif
