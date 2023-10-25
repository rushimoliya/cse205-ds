class Solution {
    bool helper(TreeNode* p, TreeNode* q)
    {
        if(p==NULL&&q==NULL)
            return true;
        else if(p==NULL&&q!=NULL)
            return false;
        else if(p!=NULL&&q==NULL)
            return false;
        else
        {
            bool l=helper(p->left,q->left);
            bool r=helper(p->right,q->right);
            return (p->val==q->val)&&l&&r;
        }   
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
};