#include <stdio.h>
 
int main()
{
  int a = 10, b = 5;
 
  // algo to swap 'a' and 'b'
  a = a ^ b;  // a becomes (a ^ b)
  b = a ^ b;  // b = (a ^ b ^ b), b becomes a 
  a = a ^ b;  // a = (a ^ b ^ a), a becomes b
 
  printf("After Swapping the value of: a = %d, b = %d\n\n", a, b);
 
  return 0;
}

/*
//Another approach

#include <stdio.h>
 
int main()
{
  int a = 10, b = 5;
 
  // algo to swap 'a' and 'b'
  a = a + b;  // a becomes 15
  b = a - b;  // b becomes 10
  a = a - b;  // fonally a becomes 5
 
  printf("After Swapping the value of: a = %d, b = %d\n\n", a, b);
 
  return 0;
}
*/