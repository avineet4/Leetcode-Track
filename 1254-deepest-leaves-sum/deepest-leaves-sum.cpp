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
    int deepestLeavesSum(TreeNode* root) {
        int lastLevelSum = 0;
        if(!root) return lastLevelSum;

        lastLevelSum += root -> val;
        queue<TreeNode*> pendingNodes;

        if(root -> left) pendingNodes.push(root -> left);
        if(root -> right) pendingNodes.push(root -> right);

        while(pendingNodes.size()) {
            int pendingNodesSize = pendingNodes.size();
            int sum = 0;

            for(int i = 0; i < pendingNodesSize; ++i) {
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();

                if(front -> left) pendingNodes.push(front -> left);
                if(front -> right) pendingNodes.push(front -> right);

                sum += front -> val;
            }

            lastLevelSum = sum;
        }

        return lastLevelSum;
    }
};