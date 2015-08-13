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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)return head;
        ListNode *front, *behind, *node;
        front = head;
        behind = head;
        for(int i = 0; i != n; i++)
            front = front->next;
        if(front == NULL)
        {
            node = head;
            head = head->next;
        }else{
            while(front->next != NULL)
            {
                behind = behind->next;
                front = front->next;
            }

            node = behind->next;
            behind->next = behind->next->next;
        }
        delete(node);
        return head;
    }
};