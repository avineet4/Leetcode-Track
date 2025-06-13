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
        if(root == NULL) return NULL;
        if(root -> val == p -> val || root -> val == q -> val) return root;

        TreeNode* leftOutput = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightOutput = lowestCommonAncestor(root -> right, p, q);

        if(leftOutput == NULL && rightOutput != NULL) return rightOutput;
        else if(leftOutput != NULL && rightOutput == NULL) return leftOutput;
        else if(leftOutput != NULL && rightOutput != NULL) return root;
        else return NULL;
    }
};