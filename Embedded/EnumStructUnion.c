/*
Enumeration (or enum) is a user defined data type in C.
It is mainly used to assign names to integral constants, the names make a program easy to read and maintain.
Two enum names can't have same value
declared globally

*/
	enum day {Mo,Tu,We,Th,Fr,Sa,Su};
	enum day day_var;

	or

	enum day {Mo,Tu,We,Th,Fr,Sa,Su} day_var;

	day_var = Wed 	//output = 2
	//or
	int i = Tu;		//i take the num type now

--
//Enums must be unique. Else compilation error
	
	enum state  {working, failed}; 
	enum result {failed, passed};	//ERROR .. failed declared in 2 enums







ToDO: enum vs macro