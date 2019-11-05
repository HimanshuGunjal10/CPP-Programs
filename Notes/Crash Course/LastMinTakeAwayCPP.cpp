friend ostream& operator << (ostream& outs, const student& stud);
friend istream& operator >> (istream& ins, student& stud);

ostream& operator << (ostream& outs, const student& stud)
{
	outs << stud.id << " " << stud.name << endl;
	return outs;
}
istream& operator >> (istream& ins, student& stud)
{
	cout << "Enter id +space+ name + enter" ;
	ins >> stud.id >> stud.name;
	return ins;
}

--

try
{
	...
	if (condition)
		throw(99);		//throw(99)
}
catch (int x)
{
	if(x==99)						// check that integer value
		cout << "erro No." << x << endl;
}

catch(...)
{
	cout << "Generic message" << endl;		//NOTE: no parameter can be passed to this catch function. throw(99) is ok, but this fn won't process the '99'
} 

--

#include<fstream>

ofstream fileObj;
fileObj.open("Tuna.txt");
fileObj << "Replaces and not appends";
fileObj.close();

//writing to file
if fileObj.is_open()
{
	//do your stuff
	while(cin>>name>>id)
		fileObj << name << id << endl;
}
//reading from file
ifstream inFile("Bacon.txt");	//used a constructor
if(inFile.is_open())
{
	while(inFile>>name>>id)		//not inFile and not cin
		cout << name << id << endl;
}

--

read the full inheritence from bucky

--
	/* COVERS ENTIRE arrays.cpp file */

int arr[10];
char carr[] = "Hemu";
char carr[10];
char arrptr*;
arrptr = carr

printf("%s",carr);
scanf("%s",rarr);

//prefer
puts(carr);
fputs(carr,stdout);	//does not move cursor to next line

unsigned int size = sizeof(arr)/sizeof(arr[0]);

void foo(int arr[], unsigned int size);
void foo(int *arrptr, unsigned int size);

//char array v/s pointers to string literals
	char s[] = "himanshu" //creates a character array of size 9 ('\0' added) _ stored in stack (actually displayed size is 8 and not 9) 
	char *strptr = "geeksquiz"	//creates pointer to a string literal _ 'strptr' stored in stack but 'geeksquiz' stored in read only mem ***
	
	s[0] = 'j';	//valid...output= jeeksquiz
	strptr[0] = 'j';	//invalid _ segmentation error since code section is read only.

	s = "NewName"	//invalid
	strptr = "NewName"; 	//valid as its stored in read only mem

	puts(++strptr);	//ewName //N is gone now

--
gets()
	char s[10];	//should read only till 10 as buffer size is 10.
	gets(s)	//no buffer overflow. reads until end of line character

	soln:
	char s[MAX_LIMIT];
	fgets(s,MAX_LIMIT,stdin)
--

swapping strings

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
--

passing by reference:

	string s = "Himanshu";
	print(s);
	reverse(s);
	print(s);

	void reverse(string s)
	{	s[0] = 'G';	}		//o/p = Himanshu
	
	void reverse(string& s)
	{	s[0] = 'G';	}		//o/p = Gimanshu
	

--
int main(int argc, char argv[])

--

delete - operator, for new objs
free - function, for malloc

delete temp;
temp = nullptr;

free(temp); //
 if you don't set deleted pointers to 0, you will get into trouble if you're doing double deletes.

More on pointers:
https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html

--------------------------------------------------------
--------------------------------------------------------

class stack
{
	int size;
	int top;
	int arr*;

public:
	stack(int n)
	{
		size = n;
		top = -1;
		arr = new int[size];
	}
}
----------------------------
struct Queue
{
	int front, rear, size;
	unsigned int capacity;
	int* arr; 
}

struct Queue* createQueue(int cap)
{
	//Queue* myQ = new Queue;
	struct Queue myQ = (struct Queue*) (malloc(sizeof(struct Queue)));
	myQ->capacity = cap;
	myQ->size = 0;
	myQ->front = 0;
	myQ->rear = capacity-1;
	//myQ->arr = new int[capacity];
	myQ->arr = (int*)(malloc(sizeof(int)*capacity));
	return myQ;
}
----------------------------

------------
EMBEDDED
-----------
	int a=5; int b=10;
  // algo to swap 'a' and 'b'
  a = a ^ b;  // a becomes (a ^ b)
  b = a ^ b;  // b = (a ^ b ^ b), b becomes a 
  a = a ^ b;  // a = (a ^ b ^ a), a becomes b

--

Amazon qn

#define ADDR 0x12345678

int main()
{
	volatile uint32_t ptr* = (volatile uint32_t*)ADDR;
	uint32_t var = 0;
	while(1)
	{
		if(var != *ptr)
		{
			var = *ptr;
			cout << var;
		}	
	}	
}

NOTE: #define addresses are stored as unsigned int 
so if you are using a pointer access the address, always typecast the #defined addresses
--

print binary using recursion
void print_binary(int num)
{
	if(num != 0)
	{
		print_binary(num>>1);	//note call this way so that number is not printed in reverse
		if(num & 1)
			printf("1");
		else
			printf("0");
		num = (num>>1);
	}
}

OR

void printBinary(int num)
{
	if(num<2)
		cout << num;
	else
	{
		printBinary(num>>1); // OR printBinary(num/2);
		cout << num%2;
	}
}

--

int main()
{
	int num = 10;
	print_binary(num);

	printf("\nLa Fin!");
}

OR 

void print_binary(int num)
{
	printf("%d",(num & 0x80)? 1:0);
	printf("%d",(num & 0x40)? 1:0);
	printf("%d",(num & 0x20)? 1:0);
	printf("%d",(num & 0x10)? 1:0);
	printf("%d",(num & 0x08)? 1:0);
	printf("%d",(num & 0x04)? 1:0);
	printf("%d",(num & 0x02)? 1:0);
	printf("%d",(num & 0x01)? 1:0);
}

------

int calculateSetBits2(int num)	//Efficient code
{
	int count = 0;
	while(num)
	{
		count += num & 1;
		num >>= 1;		// num >> 1 has no effect as no assignment so num = num >> 1
	}
	return count;
}

------

//LE or BE
	uint32_t num = 1;		//don't do uint8_t
	char* ptr = (char*)&num;
	//char* c store the 1st byte only
	//so if 1 is stored, then Little else Big

	if(*ptr)
		cout << "This computer uses Little Endian" << endl;
	else
		cout << "This computer uses Big Endian" << endl;

-----

Bit mapped struct: 
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

-
//OR a simple one
typedef struct
{
    unsigned int x : 1;
} uint1_t;
this will still use minimum 8 bits though but you can store or access just the 1 bit.

--
malloc, calloc, realloc - If there is no space available, these functions return a null pointer.

memory leak - when you forget to relase dynamic mem created by you.

--

int CheckPowerOftwo (unsigned int x)
{
  return ((x != 0) && !(x & (x - 1)));
}

--

Slow-Fast runners

	while(fast != nullptr)
	{
		fast = fast->next;
		if(fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

--
Queue

	class Queue
	{
		int *arr;
		int front, rear, size;
		unsigned int capacity;
	public:
		Queue(int cap); ... //other functions
	};
--
	void Queue::enqueue(int item)
	{
		if(isFull())
			return;
		rear = (rear+1)%capacity;	//imp
		arr[rear] = item;
		size++;
	}

	void Queue::dequeue()
	{
		if(isEmpty())
			return;
		front = (front+1)%capacity;
		size--;
	}

--
Finding a value
vector:

	//finds occurrence of 1st of smallest and immediate greater than element
	vector<int>::iterator it1 = lower_bound(vec.begin(), vec.end(), 100);
set:

//since it is already sorted no need to pass the begin and end here (unlike vectors)
	set<int>::iterator it = s.find(-10);
	//returns the iterator if found or the iterator s.end() if not found

OR for vectors:
	//sort O(Nlog(N))
	sort(vec.begin(),vec.end());
	print(vec);

	//binary search after sorting O(log(N))
	bool flag1 = binary_search(vec.begin(), vec.end(), 50);

---

Trees
	//get nodes at level k
	void getNodes(Node* node, int level)
	{
		if(node == nullptr && level<0)
			return;

		if(level==0)
			cout << node->data;

		getNodes(node->left,level-1);
		getNodes(node->right,level-1);
	}


------

Vectors:

sort(v.begin(),v.end()); 	// Olog(NlogN)

bool present = binary_search(v.begin(),v.end(), 3);	//O(logN)

//O(logN)
lower_bound >=
upper_bound >

//1,2,3,5,100,100,100,100,123
vector<int>::iterator it1 = lower_bound(v.begin(),v.end(),100);
vector<int>::iterator it2 = upper_bound(v.begin(),v.end(),100);

LB -> 100, UB --> 123
*it1 -> 100, *it2 -> 123
it2-it1 = 4 (4-0 = 4 --> 123 -100 the index)

------
Set:

set<int> s;
s.insert(10);

set<int>::iterator it = s.find(10);
//or
auto it = s.find(10);
if(it == s.end())
	cout << "not found";

auto it2 = lower_bound(10); 	//since its already sorted, no need to give begin and end

/O(logN)
s.erase(it2);


-

set<pair<int,int>> s;

s.insert({2,3});
s.insert({100,200});

//how are sets of pairs ordered?
{a,b} and {c,d}
sets are ordered on the first and if first elements are equal, they are ordered on the second
if a<c then {a,b} will be before {c,d}
if a==c, then if b<d then {a,b} will be before {c,d} or the reverse.


=============================================
https://www.youtube.com/watch?v=g-1Cn3ccwXY
watch from 29th minute
=============================================


	vector<int> res;
	res.assign(nums.size(),0);			//**** returns size number of zeroes	//imp
	return res;

	e.g
	res.assign(5,10);	// 10 10 10 10 10 (five tens)
	res.assign(count, value);


389. Find the Difference Leet code
    char findTheDifference(string s, string t)
    {
		int s_count = 0;
		int t_count = 0;
		for(unsigned int i=0; i<s.length(); i++)
		{
			s_count += (int)s[i];
			t_count += (int)t[i];
		}
	    t_count += (int) t[t.length()-1];    //for the extra last char
		return (char)(t_count - s_count);
    }

    convert char ascii value to int and vice versa.

 --

 my_map[i]++; //increments the value of the particular key.

 myUnorderedSet.erase(it);

--
for less amount, dont use hashmap but use a array
initialize a vector for 26 alphabets as:
vector<int> vec(26);


--
//****imp
read words from a sentence
#include<sstream>

string str = "Hello fro mthe dark side";
string temp;
stringstream ss(str);
while(ss >> temp)
	...