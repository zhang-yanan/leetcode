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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *r, *temp, *p;
        while(head != NULL && head->val == val)
        {
            p = head;
            delete p;
            head = head->next;
        }
        p = head;
        while(p != NULL)
        {
            if(p->val == val)
            {
                temp = p;
                r->next = p->next;
                p = p->next;
                delete temp;
            }else{
                r = p;
                p = p->next;
            }
         
        }
        return head;     
    }
};