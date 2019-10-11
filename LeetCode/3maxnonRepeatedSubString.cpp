#include<iostream>
#include<string>
#include<set>
using namespace std;

/*
 * "abcbcdab"
 *
 *	Brute force method
 * */

int compute(string str, int start_point)
{
	int length=0;
	set<int> myset;
	for(unsigned int i=start_point; i<str.size();i++)
	{
		//if(myset.find(str[i]))	//does not return a bool but an iterator. So, can't use this
		set<int>::iterator it;
		it = myset.find(str[i]);

		if(it == myset.end())
		{
			length++;
			myset.insert(str[i]);
		}
		else
			break;
	}

	return length;

}

int find_max(string str)
{
	int max_length = 0;
	int length = 0;
	for(unsigned int i=0; i<str.size(); i++)
	{
		length = compute(str,i);
		if(length > max_length)
			max_length = length;
	}
	return max_length;
}


int main()
{
	string str = "aaaaa";
	int max_length = find_max(str);

	cout << "max_length = " << max_length;
	return 0;
}



-----------------
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*
//Note 2 Line solution:
v.erase(unique(v.begin(),v.end())); //***** remove duplicates in a vector
return v.size();

*/

class Solution {
public:
	void print(vector<int>& vec)
	{
		for(vector<int>::iterator it = vec.begin(); it!=vec.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

    int removeDuplicatesAndEditArray(vector<int>& nums)
    {
        set<int> mySet;
        int count = 0;
        //cout << nums.size() << endl;
        for(unsigned int i=0; i<nums.size(); i++)
        {
            //cout << nums[i] << endl;
        	if(mySet.find(nums[i])!= mySet.end())
               {
        			nums.erase(nums.begin()+i);
        			i--;							//****** imp
               }
            else
               {
                   count++;
                   mySet.insert(nums[i]);
               }
        }

        return count;
    }

    int removeDuplicates(vector<int>& nums)	//just get the count, so no need to erase just count.
    {	//no need for set here. also already sorted.

    	//nums.erase(unique(nums.begin(),nums.end())); //***** remove duplicates in a vector

    	int i=0;
    	if(nums.size()==0)
    		return 0;
    	int count=1;
    	for (unsigned int j=1; j<nums.size(); j++)
    	{
    		if(nums[i]!=nums[j])
    		{
    			i=j;
    			count++;
    		}
    	}
    	return count;
    }

};


int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	s.print(v);
	cout << "#of non-repetitive elements= " << s.removeDuplicates(v) << endl;

	s.print(v);

	cout << "#of non-repetitive elements after removing from array= " << s.removeDuplicatesAndEditArray(v) << endl;
	s.print(v);

	return 0;
}
