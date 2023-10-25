class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        using iter = std::vector<int>::iterator;
        using stack_entry = std::tuple<TreeNode**, std::pair<iter, iter>, std::pair<iter, iter>>;
        auto stack = std::stack<stack_entry>();

        TreeNode * root = nullptr;
        stack.emplace(&root, 
            std::pair(preorder.begin(), preorder.end()), 
            std::pair(inorder.begin(), inorder.end()));

        while (!stack.empty()) {
            auto [parents_link, pre, in] = stack.top();
            stack.pop();
            if (pre.first == pre.second)
                continue;

            auto * node = new TreeNode(*pre.first);
            *parents_link = node;
            const int nodes_in_left_subtree = std::distance(
                in.first, std::find(in.first, in.second, node->val));

            stack.emplace(
                &node->left,
                std::pair(pre.first + 1, pre.first + 1 + nodes_in_left_subtree),
                std::pair(in.first, in.first + nodes_in_left_subtree)
            );
            stack.emplace(
                &node->right,
                std::pair(pre.first + 1 + nodes_in_left_subtree, pre.second),
                std::pair(in.first + 1 + nodes_in_left_subtree, in.second)
            );
        }
        return root;
    }
};