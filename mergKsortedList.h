/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* merge(ListNode *l1,ListNode *l2 )
    {
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode *p, *q, *r, *t, *result;
        if(l1->val <= l2->val)
        {
            p = l1;
            q = l2;
        }else{
            p = l2;
            q = l1;
        }
        result = p;
        while(p != NULL && q != NULL)
        {
            while(p != NULL && p->val <= q->val)
            {
                r = p;
                p = p->next;
            }
            r->next = q;
            if(p == NULL)break;
            while(q!=NULL && q->val <= p->val)
            {
                t = q;
                q = q-> next;
            }
            t->next = p;
        }
        return result;
    }
ListNode* mergeK(int left, int right, std::vector<ListNode*>& lists)
    {
        if(left < right)
        {
            int mid = left + (right - left)/2;
            return merge(mergeK(left, mid, lists),mergeK(mid+1, right, lists));
        }
        return lists.at(left);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() > 0)
        {
            ListNode *result = mergeK(0, lists.size()-1, lists);
            return result;
        }else return NULL;
    }
};