#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int i= digits.size()-1;
	int carry = 1;
	while(i>=0)
	{
		digits[i] += carry;
		if(digits[i]<10)
			return digits;
		else
		{
			digits[i] = digits[i]%10;
			carry = 1;
		}
		i--;
		if(i==-1)
			digits.insert(digits.begin()+0,1);
	}
	return digits;
}

void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i];
	cout << endl;
}

int main()
{
    cout << "Hi Hemu" << endl;
    vector<int> v;
    v.push_back(9);
    v.push_back(0);
    v.push_back(9);


//    v.push_back(9);

    vector<int> res;
    res = plusOne(v);

    print(res);

    cout << "La Fin";
    return 0;
}


//
attempt 1:
right in eclipse but LC was giving runtime error

vector<int> plusOne(vector<int>& digits)
{
	int i = digits.size()-1;
	int carry = 1;
	if(digits.back() != 9)
	{
		digits[i] += 1;
		carry = 0;
	}
	else
	{
		while(digits[i]==9)
		{
			digits[i] += carry;
			carry = digits[i]/10;
			digits[i] %= 10;
			i--;
			if(i<0)
			{
				digits.insert(digits.begin(),1);
				carry = 0;
			}
		}
		if(carry)
			digits[i] += 1;
	}

	return digits;

}