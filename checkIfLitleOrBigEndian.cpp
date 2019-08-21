/*
 * Check if computer is little or big endian
 */

#include <iostream>
using namespace std;

int main()
{
	uint32_t num = 1;
	char* c = (char*)&num;
	//char* c store the 1st byte only
	//so if 1 is stored, then Little else Big

	//*c and not c !!
	if(*c)
		cout << "This computer uses Little Endian" << endl;
	else
		cout << "This computer uses Big Endian" << endl;

	printf("\nLa fin");
	return 0;
}
