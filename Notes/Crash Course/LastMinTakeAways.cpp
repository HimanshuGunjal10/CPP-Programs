LastMinTakeAways.cpp

-----------------------------------------------------------------------------------------------------------------

http://john-ahlgren.blogspot.com/2013/10/stl-container-performance.html

-----------------------------------------------------------------------------------------------------------------

-x-
---------
VECTORS
---------

vector<int> vec3(vec2); // a copy of vec2
//Arrays are passed by reference always. Vectors are not.
//So always pass them by reference. (use &)
void foo (vector<int>& myVec);

void printVec (const vector<int>& b)	/
	if(vec.empty())	cout << "empty";
	for (unsigned int i=0; i<vec.size(); i++)
vector<int> vec;
vec.push_back(2);
OR vec[3] = 33;
printVec(vec);	//not (&vec)
cout << vec.front();
cout << vec.back();
cout << vec.at(index);

-x-
---------
POINTERS
---------

ptr++;	//increments the address the ptr points to by 4 bytes

int val[] = {1,2,3};
val is a const pointer. So, you cannot do *val++ or val++

//We pass arrays to functions as pointers to save MEMORY and TIME

// A null pointer stores a defined value, but one that is defined by the environment to not be a valid address for any member or object.
// NULL vs Void Pointer – Null pointer is a value, while void pointer is a type
    
    *(int *)ptr // void pointer dereferencing


const char* ptr = &a;
//same as
char const* ptr = &a;	//value cannot be changed. Can do ptr = &b; 

char *const p;			//value can be changed, cant change the char pointer

-x-
---------
ARRAYS
---------

 puts() moves the cursor to next line

 	string s = "Hello";
 	puts(s);
 	fputs(s, stdout)	//cursor remains in the same line

	char s[] = "himanshu" //creates a character array of size 9 ('\0' added) _ stored in stack (actually displayed size is 8 and not 9) 
	char *strptr = "geeksquiz"	//creates pointer to a string literal _ 'strptr' stored in stack but 'geeksquiz' stored in read only mem ***

	fgets(s,MAX_INPUT_SIZE,stdin);
-x-
-----
SETS 
-----

//implemented as BINARY SEARCH TREE
we cannot modify an element
traversal through iterators

//inserts in a sorted order in O(logN) time

	//sort O(Nlog(N))
	sort(vec.begin(),vec.end());

	//vec = 1,2,2,2,5,7
	vector<int>::iterator it1 = lower_bound(vec.begin(), vec.end(), 2);	//*it1 = 2 (@index 1)
	vector<int>::iterator it2 = upper_bound(vec.begin(), vec.end(), 2);	//*it2 = 5 (@index 4)
	cout << *it1 << " " << *it2 << endl;	//2 5
	cout << it2-it1 << endl;	//not the vlaue but the it count so = 4-1 = 3 (so, three occurances of element 2)

	sort(vec.begin(),vec.end());
	bool flag1 = binary_search(vec.begin(), vec.end(), 50);	//can use binary search after sorting

	make_heap(vec.begin(),vec.end());
	vec.erase(it.begin()+3);

Note:
#include<set>
and you can use set and multiset both

#include<unordered_set>
this will store it in any random order (note: its a set so no duplicates)

-x-
----
MAPS 
----

duplicate keys in maps will take the last value for the key (wont throw error but will ovwewrite the previous value)

map<int,string> myMap;
myMap[0] = "hemu";
cout << myMap[0];

//if using iterators, use it->first and it->second to access the key-value pairs

map<int,string>::iterator it;
for(it = myMap.begin(); it!=myMap.end();it++)
	cout << it->first << it->second;

cout << myMap.size();
myMap.clear() //empties map. now size = 0;

myMap.insert(pair<int,string>(2,"Himanshu"));	//use pairs

map<int,string>::iterator it = myMap.find(2);	//note: use .find function to return an iterator an then erase that iterator
myMap.erase(it);

if(myMap.empty())	//returns bool


-x-

-----
LL 
-----

insert()
	if head = 0; insert at head
	else use temp; insert when curr->next = null as curr->next;

remove() use current and prev pointers

	while(curr!= NULL && curr->value != value)
	{
		prev = curr;
		curr = curr->next;
	}



//Note: demystifying passing nodes as * and ** and *&
	Node* head = NULL;
	insert(&head,5)	---> void insert(Node** head, int value);	//you want to change the head

	insert(head,5)	---> void insert(Node* &head, int value);	//you want to change the head

	print(head)	---> void print(Node* head);					//you don't want to change the head


---------
DEQUE
---------

A better version of vectors.
With functions as 
push_back() pop_back()
push_front() pop_front()
size() iterator it begin() end() clear() erase()



int* arr = new int[size];

2 stacks in 1 array
inititalize top1 = -1 and top2 = size
fill arrays from both end by ++top1 and --top2 //*****
before that check overlap condition top1<top2-1 (since doing top++)


----------
STACKS 
----------

class StackNode
{
public:				//use public if not accessing using objects
	int data;
	StackNode* next;
};

bool isEmpty(StackNode* root)
{
	return !root;
}


//reverse a string
	int capacity = strlen(str);
	Stack* stack = createStack(capacity);

//stack of array
Stack* createStack(int capacity)
{
	Stack* temp = new Stack;
	temp->top = -1;
	temp->capacity = capacity;
	temp->array = new char[sizeof(char)*capacity];
	return temp;
}


------
Notes
------

vectors:
Insertion does not invalidate iterators as long as no reallocation is performed .
when reallocating, all iterators become invalid
Deletion invalidates all iterators after the deleted element, iterators to elements BEFORE are still valid.

Dequeue:
All iterators may become invalid after an insertion or deletion, but pointers/references are always valid. //***//


sort(vec.begin(),vec.end());
bool flag = binary_search((vec.begin(),vec.end(),50);	//serach for element 50


unordered_set and unordered_map has constant time performance on all operations provided no collisions occur.

Deletion does not invalidate any iterators (other than erased element).
Insertion keeps all iterators valid as long as no rehashing is done. When rehashing is performed, all iterators become invalid.
Pointers/references to elements always remain valid.




------------
STL LIBRARY
------------

SETS
begin() – Returns an iterator to the first element in the set.
end() – Returns an iterator to the theoretical element that follows last element in the set.
size() – Returns the number of elements in the set.
max_size() – Returns the maximum number of elements that the set can hold.
empty() – Returns whether the set is empty.
rbegin()– Returns a reverse iterator pointing to the last element in the container.
rend()– Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.

so it == s.!=rend() OR != s.rbegin();

erase(5);
s.lower_bound();
s.upper_bound();

emplace() vs insert() //***//
When we use insert, we create an object and then insert it into the multiset. With emplace(), the object is constructed in-place.

// declaring set 
    set<pair<char, int>> ms; 
      
    // using emplace() to insert pair in-place 
    ms.emplace('a', 24); 
      
    // Below line would not compile 
    // ms.insert('b', 25);     
      
    // using emplace() to insert pair in-place 
    ms.insert(make_pair('b', 25));     


----------
TREES
----------

class Node
{

public:
	int data;
	Node *left, *right;
	Node(int val)		//constructor
	{
		this->data = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};


int main()
{
	Node *node 			= 	new Node(5);
	node->left 			= 	new Node(3);
	....
}



--------------
SET and pairs
--------------

#inlude<utility>

typedef pair<int,int> pairs;	//note: no = in typedef
set<pairs> s;

pairs p = make_pair(1,"One");
s.insert(p);

//without typedef

set<pair<int,int>> s;
s.insert(make_pair(1,"one"));



---------
Queue
---------

used for level order traversal

	queue<Node*> Q;		//queue is of type Node* and not int
	Q.push(root);

	//Queue to be used as:
	//1. display from front and then pop
	//2. push children at back

	while(!Q.empty())
	{
		Node* node = Q.front();
		cout << node->data << " ";
		Q.pop();					//pop the front node. not needed since printed
		//check if that node had left and right nodes. Note: thats why we save it into node
		if(node->left)
			Q.push(node->left);
		if(node->right)
			Q.push(node->right);
	}

--
#include <iostream>
#include <set>
using namespace std;

int main(){

    typedef pair<int, int> pairs; //creating pair as default data type 
    pairs p[5]; //array of pair objects
    for (int i =0; i<5; i++){
        p[i].first= (i+1)*10; //inserting first element of pair
        p[i].second = (i+1); //inserting first element of pair
    }
    set<pairs> s;   //set to sort pair
    set<pairs> :: iterator it; //iterator to manipulate set

    for (int i =0; i<5; i++){
        s.insert(p[i]); //inserting pair object in set
    }

    for (it = s.begin(); it!=s.end(); it++){
        pairs m = *it; // returns pair to m

    cout<<m.first<<" "<<m.second<<endl; //showing pair elements				//m.first or it->first
    }
    return 0;
}


---
use maps to store nodes (print vertical tree code)

map<int,vector<int>> m;

m[count].push_back[node->data];		//(****)

---	
memset to create lookup table and initialize all values to -1
    int n = str.length(); 
  
    // Create and initialize lookup table 
    int lookup[n]; 
    memset(lookup, -1, sizeof lookup); 