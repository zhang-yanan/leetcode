/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *reverse(ListNode * head)
    {
        if(head == NULL)return head;
        ListNode *m, *n, *r;
        m = head;
        n = head->next;
        r = n->next;
        m->next = NULL;
        n->next = m;
        while(r!=NULL)
        {
            m = n;
            n = r;
            r = r->next;
            n->next = m;
        }
        return n ;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||k <= 1) return head;
        ListNode *p = head, *q = head, *temp,*r;
        int nums = k;
        while(p!=NULL && nums != 1)
        {
            p = p->next;
            nums--;
        }
        if(p == NULL || nums > 1) return head;
        temp = p->next;
        p->next = NULL;
        head = reverse(q);
        r = p = temp;
        while(p != NULL)
        {
            nums = k;
            while(p!=NULL && nums != 1)
            {
                p = p->next;
                nums--;
            }
            if(p == NULL ||nums > 1)
            {
                q->next = r;
                break;
            }
            else
            {
                temp = p->next;
                p->next = NULL;
                q->next = reverse(r);
            }
            q = r;
            p = r = temp;
        }
        return head;
    }
};