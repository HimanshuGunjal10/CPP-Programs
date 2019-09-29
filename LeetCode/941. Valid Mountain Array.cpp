#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& A)
{

	int size = A.size();
	if(size<3)
		return false;

	int i=0;

	while(A[i+1]>A[i])
	{
		i++;
		if(i+1 == size)
			break;
	}
	if(i==0 || i==size-1)
		return false;
	while(A[i+1]<A[i])
	{
		i++;
		if(i+1 == size)
			return true;
	}
	return false;
}

void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i];
	cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(5);
//    v.push_back(2);

    print(v);

    if(validMountainArray(v))
    	cout << "True\n";
    else
    	cout << "False\n";



    cout << "La Fin";
    return 0;
}
