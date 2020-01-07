vector<int> v;
v.push_back(5);
v.size();
v.pop_back()
v.insert(v.begin()+5,6);
v.swap(v2);
v.clear();	//removes all
v.erase(it);
v.erase(v.begin()+5);
v.erase(v.begin()+2,v.begin()+3);


string str;
getline(cin,str); 
cout << str;
str.push_back('s'); 
str.pop_back(); 
s.length();
s.size();
s.begin();
s.end();
	char arr[50];
	s.copy(arr,5,0);	//(char array, length to copy, starting index)
s.swap(s2);
string s3 = s.substr(3,5);	//(starting index, length)
	int index = s.find(s3);	//returns starting index if found
	if(index != s.npos())	cout << "Found at" << n;


stack<int> s;
s.top();
s.push(5);
s.pop();
!s.empty();

queue<int> q;
q.front();
q.back();
q.push(5);
q.pop();
!q.empty();

set<int> s;
s.insert(5);
!s.empty();
s.begin();
s.end();
s.erase(it);
s.erase(5);
s.erase(s.begin()++,s.end());	//only 1st element will remain
s.clear();

