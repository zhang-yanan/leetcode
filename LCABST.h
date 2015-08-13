/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *result, *temp = root;
        if(p ==NULL || q==NULL)return result;
        int min = p->val<q->val?p->val:q->val;
        int max = p->val>q->val?p->val:q->val;
        while(temp != NULL)
        {
            if(min > temp->val)
                temp = temp->right;
            else
                if(max < temp->val)
                    temp = temp->left;
            else
                break;
        }
        result = temp;
        while(temp != NULL)
        {
            if(temp->val == min)
                break;
            if(min > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        if (temp == NULL)return temp;
        temp = result;
        while(temp != NULL)
        {
            if(temp->val == max)
                break;
            if(max > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        if(temp == NULL)return temp;
        return result;  
    }
};