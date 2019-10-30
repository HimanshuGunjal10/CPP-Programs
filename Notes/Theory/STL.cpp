STL Library = algorithm, containers, functions, iterators

----------------
VECTORS/STRINGS
----------------
vector<int> v;

------
DEQUE
------
deque<int> dq;

------
SET
------
set<int> s;

------
MAP
------
map<int,string> m;

  
// insert elements in random order 
m.insert(pair<int, int>(1, "One"));

------
STACK
------

------
QUEUE
------


-------
PAIR
------
#include <utility>

pair<int,string> p;
p.first = 1;
p.second = "One";

pair<int,string> p2 (2,"Two");

pair<int,string> p3;
p3 = make_pair(3,"Three")

pair<int,string> p4 = make_pair (4,"Four");

p1.swap(p2);

pair p4(p3);	//using copy constructor
