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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if(!root) return result;

        stack<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        while(!pendingNodes.empty()) {
            TreeNode* front = pendingNodes.top();
            pendingNodes.pop();
            result.push_back(front->val);

            if(front->right){
                pendingNodes.push(front->right);
            }

            if(front->left){
                pendingNodes.push(front->left);
            }
        }

        return result;
    }
};