#include<stdint.h>	//To usee uint8_t and all

#define FLAG_ADDR 0xAABBCCDD;
main():
	uint32_t *ptr = NULL;
	ptr =  FLAG_ADDR;
error: invalid conversion from 'unsigned int' to 'uint32_t*'

NOTE: #define addresses are stored as unsigned int 
so if you are using a pointer access the address, always typecast the #defined addresses

//for e.g.
	unsigned int *ptr = NULL;
	ptr =  (unsigned int*)FLAG_ADDR;

//OR

	volatile uint32_t *ptr = NULL;
	ptr =  (volatile uint32_t*)FLAG_ADDR;

// OR in one line

	volatile uint32_t *ptr = (volatile uint32_t*)FLAG_ADDR;

-x-

RISC vs CISC

RISC :
smaller set of instructions with few addressing nodes.
It has no memory unit.
It does not require external memory for calculations.
Execution time is very less.
Doesnt stall often
Used in high-end applications such as video processing, telecommunications and image processing.
(whereas cisc is Used in low-end applications such as security systems, home automations, etc.)


-x-

stack overflow occurs if the call stack pointer exceeds the stack boundary.
so segmentation fault -> program crash
Reasons:
	Improper use of the recursive function.
	Passing to much arguments in the function.
	Passing a structure directly into a function.
	Nested function calls.
	Creating a huge size local array.

-x-

I2C vs SPI:
I2C is:
half vs full
2 wires vs 3-4 wires
longer distance vs short distance
nxp vs motorola

less succeptible to noise
cheaper
ack after each byte. So data send is ensured
multiple masters so supports arbitration
multiple devices on same bus w/o more wires or select lines

slower
draws more power
logic needs a pullup resister
extra over head due to start and stop bits


"One great difference between I2C and SPI is that I2C supports multiple devices on the same bus without any additional select lines (work on the basis of device address)
while SPI requires additional signal (slave select lines) lines to manage multiple devices on the same bus."

-x-

"Limitations of I2C"
Half-duplex communication, so data is transmitted only in one direction (because of the single data bus) at a time.
Since the bus is shared by many devices, debugging an I2C bus (detecting which device is misbehaving) for issues is pretty difficult.
The I2C bus is shared by multiple slave devices if anyone of these slaves misbehaves (pull either SCL or SDA low for an indefinite time) the bus will be stalled.
No further communication will take place.
I2C uses resistive pull-up for its bus. Limiting the bus speed.
Bus speed is directly dependent on the bus capacitance, meaning longer I2C bus traces will limit the bus speed.

-x-

async vs sync

1 byte or char at a time
needs start and stop bit overhead
longer distance
cheaper
no common clock required
slower

-x-

bit rate vs baud rate
#bits per sec vs no of signal units per sec
baud rate is used to determine band width
bit rate = baud rate x #bits per signal unit

-x-

segmentation fault occurs when a program tries to access a memory location that it is not allowed to access
or tried to access a memory location in a way that is not allowed (tried to access read-only memory) or kernel space

Causes:
Dereferencing NULL pointers.
Tried to write read-only memory (such as code segment).
Trying to access a nonexistent memory address (outside process’s address space).
Trying to access memory the program does not have rights to (such as kernel structures in process context).
Dereferencing the freed memory (after calling the free function) 
A buffer overflow (try to access the array beyond the boundary) is also cause of the segmentation fault.

-x-
why not use just int ?
Primarily size of integer depends on the type of the compiler which has written by compiler writer for the underlying processor.
which may be different for different writers.
So, not to be dependent, write generic code.
C99 std defines uint8_t etc dta types.

-x-

macro VS function

no type checking				type checking
pre-processed				compiled
so, difficult to debug		easy
code length increases		stays same
faster Execution 			slower
for small code 				large code

-x-

typedef is just an alias 
e.g. 
	typedef unsigned int UnInt;
	UnInt a;	

macro is total substitution
	#define VALUE 10

-x-

enum is user-defined data type and it consists a set of named constant integer.
An enumeration increases the readability of the code and easy to debug in comparison of symbolic constant (macro).

enum day{mon,tue,wed};

-x-

The const keyword is handled by the compiler, in another hand, a macro is handled by the preprocessor directive.
There is type checking is occurred with const keyword but does not occur with #define.
const is scoped by C block, #define applies to a file.

-x-

int num = 72;
int n = 4; //4th bit

num |= (1<<4);
num &= ~(1<<4);
num ^= (1<<4); //xor to toggle
int bit = num & (1<<4);	//to check nth bit's value

-x-
to have a variable store only 1 bit, define a structure and access that bit using dot . operator e.g. here CommsLineStatus.MessageRead
typedef struct
{
  unsigned char TransmitBusy  : 1 ;
  unsigned char DoXonXOff     : 1 ;
  unsigned char XOffHold      : 1 ;
  unsigned char LastCharHadMP : 1 ;
  unsigned char MessageRead   : 1 ;
  unsigned char BadMessage    : 1 ;
  unsigned char LinkBusy      : 1 ;
  unsigned char CommsError    : 1 ;
} CommsLineStatus ;

//OR a simple one
typedef struct
{
    unsigned int x : 1;
} uint1_t;
this will still use minimum 8 bits though but you can store or access just the 1 bit.

-x-
swap 2 numbers without using a 3rd variable
  int a = 10, b = 5;
 
  // algo to swap 'a' and 'b'
  a = a ^ b;  // a becomes (a ^ b)
  b = a ^ b;  // b = (a ^ b ^ b), b becomes a 
  a = a ^ b;  // a = (a ^ b ^ a), a becomes b

 -x-

 Padding
 In the case of structure or union, the compiler inserts some extra bytes between the members of structure or union for the alignment
 these extra unused bytes are called padding bytes and this technique is called padding.
 increases the performance of the processor at the penalty of memory.
 Note: Alignment of data types mandated by the processor architecture, not by language.

 -x-

 Endianness
 is the order of
 	1. bytes to store data in memory
 	2. byte transmission over a digital link.

 LE (Intel x86) MOS technology.
 BE (Motorolla,xilinx) IBM architecture, ATMEL

BE: Lowest address stores MSB
LE: L-L-L Lowest address - lowest memory - Little endian

-x-

Static memory allocation
 A global and static variable are examples
 It’s initialized only once, prior to program startup and its lifetime is throughout the execution of the program.

Dynamic memory allocation
 using library functions (malloc, calloc, or realloc) //these functions return a pointer
 If there is no space available, these functions return a null pointer.
 not destroyed by the compiler itself
 responsibility of the user to deallocate the allocated memory

"memory leak" occurs when you allocate a block of memory using the memory management function and forget to release it.
use malloc but not free it later.

the memory that is allocated by "calloc" is initialized with 0. //only difference between malloc and calloc

The "realloc" function is used to resize the allocated block of memory.
It takes two arguments:
	1. pointer to previously allocated memory 
	2. newly requested size.
The calloc function first deallocates the old object and allocates again with newly specified size.
Note: if the pointer is a null pointer, realloc behaves like the malloc function.

-x-

Dynamic memory fragmentation has 2 types:
	1. external fragmentation
	2. internal fragmentation

The external fragmentation is due to the small free blocks of memory (small memory hole) that is available on the free list but program not able to use it.
The internal fragmentation is wasted of memory that is allocated for rounding up the allocated memory and in bookkeeping (infrastructure),
the bookkeeping is used to keep the information of the allocated memory.

-x-

"Free function":
free function gets the bookkeeping information(extra info created when using malloc) and releases the allocated memory.
char *pcBuffer  =  malloc(sizeof(char) *  16); //Allocate the memory
 
pcBuffer++; //Increment the pointer
 
free(pcBuffer); //Call free function to release the allocated memory
				//results in undefined behavior

-x-
"Function pointer"

void ( *pfDisplayMessage) (const char *);

In above expression, pfDisplayMessage is a pointer to a function taking one argument, const char *, and returns void pointer.

Usecase:
	1. finite state machine
	2. to provide the feature of polymorphism in C language …etc.

-x-

Check if integer is power of 2

int CheckPowerOftwo (unsigned int x)
{
  return ((x != 0) && !(x & (x - 1)));
}


-x-

"Bit shifting" "<< >>"

Right shift of a negative signed number has implementation-defined behaviour.


-x-

"Void pointer" is generic pointer. Has no restrictions so can be used with any pointer after typecasting it.
Using the void pointer we can create a generic function that can take arguments of any data type.
The memcpy and memmove library function are the best examples of the generic function, using these function we can copy the data from the source to destination.
e.g.
	void * memcpy ( void * dst, const void * src, size_t num );

"Dangling Pointer" 
dangling pointer is a pointer that not pointing a valid object of the appropriate type and it can be the cause of the undefined behavior.
when the dynamic memory pointed to is freed, but the pointer is not changed.
When the user tries to dereference the daggling pointers than it shows the undefined behavior and can be the cause of the segmentation fault.

"Wild Pointer"
A pointer that is not initialized properly prior to its first use is known as the wild pointer.
Uninitialized pointers behavior is totally undefined because it may point some arbitrary location that can be the cause of the program crash.

int *ptr; //piData is wild pointer. Compilers MAY throw a warning but not an error.

-x-

"const" is a qualifier
const volatile uint32_t *DEVICE_STATUS = (uint32_t *) 0x80102040;

const int* p 		- value cannot be changed 
int* const p 		- pointing address cannot be changed

-x-

"static" used as global will keep the scope as only to the curremt ".c" file
With the help of the static keyword before a funciton, we can make the scope of the function local
i.e. it only accesses by the translation unit within it is declared.

A static global variable      ===>>>  internal linkage.
A non-static global variable  ===>>>  external linkage.

So global variable can be accessed outside of the file but the static global variable only accesses within the file in which it is declared.

-x-

"Reenterant function"
In computing, a computer program or subroutine is called reentrant if it can be interrupted in the middle of its execution and then safely be called again (“re-entered”)
before its previous invocations complete execution.
The interruption could be caused by an internal action such as a jump or call, or by an external action such as an interrupt or signal.
Once the reentered invocation completes, the previous invocations will resume correct execution.

-x-

extern "C" makes a function-name in C++ have 'C' linkage (compiler does not mangle the name)
so that client C code can link to (i.e use) your function using a 'C' compatible header file that contains just the declaration of your function.
Your function definition is contained in a binary format (that was compiled by your C++ compiler) that the client 'C' linker will then link to using the 'C' name.
Since C++ has overloading of function names and C does not,
the C++ compiler cannot just use the function name as a unique id to link to, so it mangles the name by adding information about the arguments.
A C compiler does not need to mangle the name since you can not overload function names in C.
When you state that a function has extern "C" linkage in C++, the C++ compiler does not add argument/parameter type information to the name used for linkage.
Just so you know, you can specify "C" linkage to each individual declaration/definition explicitly
or use a block to group a sequence of declarations/definitions to have a certain linkage

extern "C" void foo(int)
extern "C"
{
	int a;
	char b;
}


variable definition: compiler allocates memory and also does the inititalization
variable declaration: tell the compiler that a variable by that name and type exists will be defined somewhere else. (No mem allocation)

The extern keyword means "declare without defining".
If there is no definition or more than one, an error is produced, possibly in the linking stage.

-x-

"inline"  keyword is a compiler directive that only suggests the compiler to substitute the body of the function at the calling place.
It is an optimization technique used by the compilers to reduce the overhead of function calls.

static inline void Swap(int *a, int *b)
{
  int tmp= *a;
  *a= *b;
  *b = tmp;
}

replaces the keyword by the body of the function.
increases code size but improves performance

pros:
	saves the function calling overhead
	saves the overhead of variables push/pop on the stack, while function calling
	saves the overhead of return call from a function
cons:
	May increase function size so that it may not fit in the cache, causing lots of cache miss
	too many inline functions result in a larger code size then it may cause thrashing in memory. More and number of page fault bringing down your program performance.
	It’s NOT useful for an embedded system where large binary size is not preferred at all due to memory size constraints.

-x-

"Virtual memory" is a layer of indirection to create an illusion that the system has a sufficient amount of memory.

