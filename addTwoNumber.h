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
        if (l1 == NULL && l2 == NULL) return NULL;
        int sum = 0, acc = 0, digit = 0;
        ListNode * result = new ListNode(0);
        ListNode* temp;
        ListNode* list_ptr = result;
        
        while( !(l1 == NULL && l2 == NULL))
        {
            if (l1 == NULL)
            {
                sum = l2->val;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                sum = l1->val;
                l1 = l1->next;
            }
            else
            {
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
        
            digit = (sum +acc)%10;
            acc = (sum + acc)/10;
            temp = new ListNode(digit);
            list_ptr->next = temp;
            list_ptr = temp;
        }
        if (acc > 0)
    
        {
            temp = new ListNode(acc);
            list_ptr->next = temp;
        }
        return result->next;
        
    }
};