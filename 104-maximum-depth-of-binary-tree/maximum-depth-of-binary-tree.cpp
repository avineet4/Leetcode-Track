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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int maxDepth = 0;
        stack<pair<TreeNode*, int>> pendingNodes;
        pendingNodes.push({root, 1});

        while(!pendingNodes.empty()) {
            auto [node, depth] = pendingNodes.top();
            pendingNodes.pop();

            maxDepth = max(maxDepth, depth);

            if (node->left)
                pendingNodes.push({node->left, depth + 1});
            if (node->right)
                pendingNodes.push({node->right, depth + 1});
        }

        return maxDepth;
    }
};