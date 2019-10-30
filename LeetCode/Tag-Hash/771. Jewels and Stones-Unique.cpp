
/*
  Note: Twist in the question. Count the unique jewels in hand.
  So used set.
  For the other implementation, count all jewles in the hand, use map
*/

class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
  		unordered_set<char> u_s;
  		for(int i=0; i<J.length(); i++)
  		{
  			u_s.insert(J[i]);
  		}
  		unordered_set<char>::iterator it;
  		int count = 0;
  		for(int i=0; i<S.length();i++)
  		{
			it = u_s.find(S[i]);
			if(it != u_s.end())
			{
				count++;
				u_s.erase(it);
			}
  		}
  		return count;
    }
};