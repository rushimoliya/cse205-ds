class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);


            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                int index = l2r ? i : size - i - 1;
                v[index] = temp->val;

                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            l2r = !l2r;
            ans.push_back(v);
        }
        return ans;
    }
};