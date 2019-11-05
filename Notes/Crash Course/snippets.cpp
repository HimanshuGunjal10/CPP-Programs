1.1 check if a string is a palindrome
ask:
	ascii or unicode
	ascii 128 or extended

ASCII defines 128 characters, which map to the numbers 0–127. Unicode defines (less than) 221 characters, which, similarly,
map to numbers 0–221 (though not all numbers are currently assigned, and some are reserved).

extended ascii = 256 characters
tip: if length of string > 128 return false. as then, surely something repeats

use a bool chararray[128] = {false};	//constant space so O(1)
//
memset to initialize in C 
	memset(chararray,0,sizeof(chararray));
	//or
	memset(chararray,0,128)\

--
reduce sopace useage factor by 8

if said that only lower case a-z are present, use an int value and do bit manipulation
	int checker = 0;
	for(iterate over string)
	{
		int val = str[i] - 'a';
		if(checker & (1<<val))	//already was set
			return false;
		checker |= (1<<val);	//set if it wasnt set already
	}

------------
1.2
------------

