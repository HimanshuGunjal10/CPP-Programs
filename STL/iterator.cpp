
vector<int> vec;
vector<int>:: iterator it;

for (it=vec.begin(); it!=vec.end(); it++)
	cout << *it;
//reverse
vector<int>::reverse_iterator it;				//imp
for(it=vec.rbegin(); it != vec.rend(); it++)	//note not it--
	cout << *it;

//vector has a random access iterator
//lists have a bidirectional iterator
