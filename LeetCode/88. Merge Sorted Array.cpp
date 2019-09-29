#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{	int i=0;
int j=0;
int ins_at = 0;
bool flag = false;
if(n<1) //dont have to merge anything
    return;

//Note: In the Leet code problem, nums1 should be sliced upto m and then taken as input
nums1.erase(nums1.begin()+m,nums1.end());
//nums2.erase(nums1.begin()+n,nums1.end());

while(i<m && j<n)
{
	//merge logic
	while(nums1[ins_at]<=nums2[j])	//MISTAKE: Used < everywhere and not <=
	{
		i++;
        ins_at++;
        if(i==m)
        {
            flag = true;
            break;
        }
	}
    if(flag)
        break;
	nums1.insert(nums1.begin()+ins_at,nums2[j]);
    ins_at++;
	j++;

}

//	while(i<m)//do nothing as result is already nums1

while(j<n)
{
	nums1.push_back(nums2[j]);
	j++;
}}


void print(vector<int> vec)
{
	for(unsigned int i=0; i<vec.size(); i++)
		cout << vec[i];
	cout << endl;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(7);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(8);

    print(v1);
    print(v2);
    merge(v1,v1.size(),v2,v2.size());
    print(v1);




    cout << "La Fin";
    return 0;
}
