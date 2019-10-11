class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        vector<int> retVec; //vector<int> retVec(2) is wrong. It will initialize vec with first 2 elements as 00
        for(unsigned int i=0; i<nums.size(); i++)   //not sizeof(nums)
        {
            for(unsigned int j=0; j<nums.size(); j++)
            {
                if( (i!=j) && ((nums[i] + nums[j])==target))    //corner case (i==j) should not be the case
                {
                    //cout << nums[i] << " " << nums[j] << endl;
                    retVec.push_back(i);    //not retVec[0] = i;
                    retVec.push_back(j);    //not retVec[1] = j;
                    return retVec;
                }
            }
        }
        return retVec;
    }
};

-----------------------------------------------

Soln 2: better run time. j should be started from i+1 as we have already tested for those numbers with i

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        vector<int> retVec;
        for(unsigned int i=0; i<nums.size(); i++)
        {
            for(unsigned int j=(i+1); j<nums.size(); j++)
            {
                // if( (i!=j) && ((nums[i] + nums[j])==target))
                if(((nums[i] + nums[j])==target))

                {
                    cout << nums[i] << " " << nums[j] << endl;
                    retVec.push_back(i);
                    retVec.push_back(j);
                    return retVec;
                }
            }
        }
        return retVec;
    }
};
---------------------------------
Notes:
//vector<int> retVec(2) is wrong. It will initialize vec with first 2 elements as 00
//not sizeof(nums)
//corner case (i==j) should not be the case
//not retVec[0] = i;
//not retVec[1] = j;