function pointer:
int foo(int val)
{
    cout<<"Hey";
    return val+10;
}

int main()
{
	int (*f)(int) = &foo;
	cout << (*f)(5);
}

---
static member functions are called withour pointers
https://www.geeksforgeeks.org/c-this-pointer-question-4/

class Test 
{ 
private: 
  int x; 
  int y; 
public: 
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; } 
  static void fun1() { cout << "Inside fun1()"; } 
  static void fun2() { cout << "Inside fun2()"; this->fun1(); } 
}; 
  
int main() 
{ 
  Test obj; 
  obj.fun2(); 
  return 0; 
}


----

VECTORS

vector<int> vec;
vec.push_back(2);
OR vec[3] = 33;
printVec(vec);	//not (&vec)

cout << vec.front();
cout << vec.back();
cout << vec.at(index);

vector<int>::iterator it1 = lower_bound(vec.begin(), vec.end(), 2);	//*it1 = 2 (@index 1)
vector<int>::iterator it2 = upper_bound(vec.begin(), vec.end(), 2);	//*it2 = 5 (@index 4)

sort(vec.begin(),vec.end());
bool flag1 = binary_search(vec.begin(), vec.end(), 50);	//can use binary search after sorting

vec.erase(it.begin()+3);



-----
MAPS
-----

map<int,string>::iterator it;
for(it = myMap.begin(); it!=myMap.end();it++)
	cout << it->first << it->second;

cout << myMap.size();
myMap.clear() //empties map. now size = 0;

myMap.insert(pair<int,string>(2,"Himanshu"));	//use pairs

map<int,string>::iterator it = myMap.find(2);	//note: use .find function to return an iterator an then erase that iterator
myMap.erase(it);

if(myMap.empty())	//returns bool
