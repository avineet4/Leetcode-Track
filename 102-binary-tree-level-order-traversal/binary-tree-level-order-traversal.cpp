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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> result;

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        while(!pendingNodes.empty()) {
            int size = pendingNodes.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();

                level.push_back(front->val);
                if (front->left) pendingNodes.push(front->left);
                if (front->right) pendingNodes.push(front->right);
            }

            result.push_back(level);
        }

        return result;
    }
};