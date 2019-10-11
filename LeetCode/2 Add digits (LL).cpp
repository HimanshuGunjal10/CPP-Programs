LeetCode 2: Add digits (LL).cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

 
		ListNode* result = new ListNode(0);
		int carry = 0;
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* curr = result;

		while(p || q)
		{
			int l1val = (p != NULL) ? p->val : 0;
			int l2val = (q != NULL) ? q->val : 0;

			int sum = l1val + l2val + carry;
			int rem = sum%10;
			carry = sum/10;
			
			curr->next = new ListNode(rem);
			curr = curr->next;
			

            if(p)
            	p = p->next;
            if(q)
            	q = q->next;
		}

		// if carry remain
		if(carry>0)
			curr->next = new ListNode(carry);

		return result->next;
	
    }
};