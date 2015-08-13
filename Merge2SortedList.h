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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode *q, *p, *r,*m, *result;
        if(l1->val < l2->val)
        {
            p = l1;
            q = l2;
        }else {
            p = l2;
            q = l1;
        }
        result = r = p;
        m=q;
        while(p!=NULL &&q !=NULL)
        {
            while( p != NULL &&p->val <= q->val)
            {
                r = p;
                p = p->next;
            }
            r->next = q;
            if(p == NULL)break;
            while(q !=NULL && q->val <= p->val)
            {
                m = q;
                q = q->next;
            }
            m->next = p;
        }
        return result;
    }
};