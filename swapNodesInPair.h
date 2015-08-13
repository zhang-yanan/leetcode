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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;
        ListNode *temp, *p = head, *q = head->next;
        head = q;
       while(p!=NULL && q!=NULL)
        {
            temp = q->next;
            q->next = p;
            if(temp == NULL || temp->next == NULL)
            {p->next = temp;break;}
            else
                p->next = temp->next;
            p = temp;
            q = p->next;
        }
        return head;
    }
};