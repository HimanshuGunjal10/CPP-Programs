/*
Notes:
Use getter and setter fuctions 
getter functions should be defined as const

if you dont define a constructor then compiler will generate a default constructor that will do nothing
however if you create even 1 constructor, then you have to EXPLICITLY define the default constructor
else, student s1; will be illegal

passing objects using 'const' and '&'
	bool notFriend(const student& s1, const student& s2)
--
operator overloading-
make them friend
friend int operator -(const student& s1, const student& s2)
{
	return(s1.id - s2.id);		//in main: s1-s2
}
friend ostream& operator <<(ostream& outs, const student &s)	//imp
{
	outs << s.id << s.name << endl;	//in main: cout << s1;
	return outs;
}

//OR
friend student operator -(const student& other)	//returns type student and takes ONLY 1 object not 2 (make it const)********
{
	return(id - other.id);		//in main: s1-s2
}

--
vector of objects
using new operator

*/

//code:
#if 1

#include <stdio.h>
#include <iostream>
#include <cstring>
#include<vector>
using namespace std;

class student
{
public:
	//constructor
	student();
	student(int num, string name);
	//copy constructor
	student(const student& so);
	//destructor
	~student();
	//setters
	void setID(int num);
	void setName(string name);
	//getters
	int getID() const;		//note const is after the name
	string getName() const;	// return type is not void
	//print
	void printStud();
	//friend
	friend bool yesFriend(const student& s1, const student& s2);

private:
	int id;
	string name;
};

student::student(): id(0), name("def")	//need to define this explicitly '.' created another constructor
{	cout << "default constructor called" << endl;	}

student::student(int s_id, string s_name): id(s_id), name(s_name) {}

student::student(const student& so)
{	cout << "default copy constructor called" << endl;	}

student::~student()
{	cout << "def destructor called "  <<endl;		}

void student::setID (int s_num)
{	id = s_num;	}

void student::setName(string s_name)
{	name = s_name;	}

int student::getID() const
{	return id;	}

string student::getName() const
{	return name;	}

void student::printStud()
{	cout << "id: " << id << " name: " << name <<endl;	}

bool notFriend(const student& s1, const student& s2)	//no student::
{
	if( s1.getID() == s2.getID())	//'.'not a friend, we need to use getters
		return true;
	else
		return false;
}

bool yesFriend(const student& s1, const student& s2)	//no student:: ('.'not a student member fn)
{
	if(s1.id == s2.id)	//'.'friend, we can directly use private variables
		return true;
	else
		return false;

}

int main()
{
	student s1;
	student s2(2,"two");
	student s3;
	s3.setID(3);
	s3.setName("three");
	cout << "s1: " << s1.getID() <<endl;
	cout << "s1: " << s1.getName() <<endl;
	cout << "s2: " << s2.getID() <<endl;
	cout << "s2: " << s2.getName() <<endl;
	s3.printStud();
	student s4(2,"four");
	s4.printStud();

	cout << "same ID?- " << notFriend(s1,s2) <<endl;
	cout << "same ID?- " << yesFriend(s2,s4) <<endl;

	//vector of objects
	vector<student*> vecptr;
	vecptr.push_back(new student(9,"nine"));
	cout<< vecptr[0]->getID() << vecptr[0]->getName() << endl;
	vecptr.push_back(new student(8,"eight"));
	vecptr.push_back(new student(s3));	//using copy constructor

	//note: destrutor not called for new objects. So explicitly delete them
	//extra destructor calls invoked for these
	delete vecptr[0];
	delete vecptr[1];
	delete vecptr[2];


	return 0;
}

#endif
