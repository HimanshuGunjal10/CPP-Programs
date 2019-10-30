Bit manipulation, in some cases, can obviate or reduce the need to loop over a data structure
and can give many-fold speed ups,
as bit manipulations are processed in parallel,
but the code can become more difficult to write and maintain.

print in binary: only for cpp (not for c)
 	cout << x << "  in binary is " << bitset<32>(x) << endl;
 	//o/p: 4  in binary is 00000000000000000000000000000100

-
add 1 to an integer n
	return -~n;

-
swap
	x = x^y;
	y = x^y;
	x = x^y;

-
	x^x results in 0
-
Trick:
unset the rightmost set bit
	num = num & (num-1);
Applications:
	1. check if power of 2
	2. find position of rightmost set bit
	3. find position of only set bit

	soln:
	1. if( n & n-1) --> true then yes
	2. n ^ (n-1)

-
parity is # of 1s in the number
if even -> parity is even, otherwise odd
	while(n)
	{
		bool parity = !parity;
		n >>= 1;
	}
	return parity;

-
ASCII

dec	-	char
0		0
48		'0'
65		A
97		a

-
find the positon of character b/w a-z i.e a=1, h=8
so, & the number with 31 (011111)
	int findPositionInAZ(char c)
	{
		return int(c & 31);
	}

-
int findAbsoluteWithoutBranching(int n)
{
	int mask;
	if(n>=0)
		mask = 0;
	else
		mask = -1;
	return (n + mask) ^ mask;
	//i.e. subtract 1 and xor with -1(to flip bits)
	//reverse step of finding 

	//equivalent in 1 line as :  return (x + (x >> 31)) ^ (x >> 31);

}

-

