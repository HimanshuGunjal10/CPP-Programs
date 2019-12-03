--------------------------------------
1.1 check if a string is a palindrome
--------------------------------------
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
reduce space usage factor by 8

if said that only lower case a-z are present, use an int value and do bit manipulation
	int checker = 0;
	for(iterate over string)
	{
		int val = str[i] - 'a';
		if(checker & (1<<val))	//already was set
			return false;
		checker |= (1<<val);	//set if it wasnt set already
	}

---------------------
1.2 Check Permutation
---------------------
ask:
	case sensitive?
	whitespace significant?

if lengths are different, they arent permutations

method1:
	sort both and compare char by char
	time complexity: O(logn)

method2:
	int chararray[128];	//assumption: ASCII 128
	//s1: increment ch count
	for(ch in s1)
		chararray[ch]++;
	//s2: decrement count. If less than 0 return false
	for(ch in s2)
		if(--chararray[ch] < 0)
			return false;
	


---------------------
1.3 URLify
---------------------

2 passes
1st:
	count the number of whitespaces
2nd:
	create a new length string with new length = old + no_of_whitespaces*2
	if char == ' '
		insert 20% at new_length-1, -2 and -3
	if not
		just copy the string

IMP: such replacements always work your way from back to front so that you dont overwrite and lose string data

---------------------
1.4 Palindrome Permutation
---------------------
note: dont do map.second == 2 as it can be 4 or 6 as well
so check on map.second%2 ==1

best solution:

create a letterarray and just keep toggling the characters.
i.e if found set letterarray[i] to 1, if found again set letterarray[i] set to 0
once everything is done,
we hould be left with at most one 1 in our letterarray
i.e letterarray can be 00000000... or 0000100000 or 10000000... etc
so just check if only 1 bit was set by using num & (num-1) technique

still O(n) though but its incrementally better.
we have to visit all letters so O(n) would be for all

---------------------
1.5 One Away
---------------------
split into 2
1. check for replace function
2. check for insert/delete function

----------------------
1.6 String Compression
----------------------

Note: string concatenation is O(n^2)
