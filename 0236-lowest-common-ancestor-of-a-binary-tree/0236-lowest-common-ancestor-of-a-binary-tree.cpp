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
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // Base case:
        // If root is NULL, or root itself is p/q,
        // return root.
        if (root == NULL || root == p || root == q)
            return root;

        // Search for p/q in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search for p/q in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // Nothing found on left → answer is on right
        if (left == NULL)
            return right;

        // Nothing found on right → answer is on left
        else if (right == NULL)
            return left;

        // Both sides found something →
        // p and q are on opposite sides,
        // so current root is their LCA
        else
            return root;
    }
};