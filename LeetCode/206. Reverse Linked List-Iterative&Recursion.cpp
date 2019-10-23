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
    ListNode* reverseList(ListNode* head) {
/*        
        //iterative method O(n) time and O(1) const space
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        if(head == NULL || head->next == NULL)
            return head;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
*/
        //Recursive List O(n) time and O(n) space cz of the call stack
                //Recursive List O(n) time and O(n) space cz of the call stack

        //base case
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* rev_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev_head;    //need to save the head so pass it through every stack
    }
};