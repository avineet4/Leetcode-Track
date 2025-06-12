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
    pair<int, int> heightDiameter(TreeNode* root) {
        if(!root) {
            return {0, 0};
        }

        pair<int, int> leftAns = heightDiameter(root -> left);
        pair<int, int> rightAns = heightDiameter(root -> right);

        int ld = leftAns.second;
        int lh = leftAns.first;
        int rd = rightAns.second;
        int rh = rightAns.first;

        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld, rd));

        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return heightDiameter(root).second;
    }
};