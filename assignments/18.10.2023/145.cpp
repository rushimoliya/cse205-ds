/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void postorder(TreeNode* root, vector<int> &vct){
        if(root == NULL){
            return;
        }

        postorder(root->left,vct);
        postorder(root->right,vct);
        vct.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vct;
        postorder(root,vct);
        return vct;
    }
};