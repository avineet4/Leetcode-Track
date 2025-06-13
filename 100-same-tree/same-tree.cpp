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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> queueP, queueQ;
        queueP.push(p);
        queueQ.push(q);
        
        while (!queueP.empty() && !queueQ.empty()) {
            TreeNode* nodeP = queueP.front(); queueP.pop();
            TreeNode* nodeQ = queueQ.front(); queueQ.pop();
            
            // Both are null – continue
            if (!nodeP && !nodeQ) continue;
            
            // One is null or values differ – not same
            if (!nodeP || !nodeQ || nodeP->val != nodeQ->val) return false;
            
            // Push children to queue
            queueP.push(nodeP->left);
            queueQ.push(nodeQ->left);
            queueP.push(nodeP->right);
            queueQ.push(nodeQ->right);
        }

        return queueP.empty() && queueQ.empty();
    }
};