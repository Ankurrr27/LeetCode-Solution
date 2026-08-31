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

    TreeNode* bstFromPreorder(vector<int>& A) {

        // i keeps track of the current element in preorder
        int i = 0;

        // Initially, there is no upper limit
        // so we can use the maximum possible integer.
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {

        // If all elements are processed OR
        // the current element is greater than the allowed bound,
        // this node cannot belong to this subtree.
        if (i == A.size() || A[i] > bound)
            return NULL;

        // Current preorder element becomes the root
        TreeNode* root = new TreeNode(A[i++]);

        // Build the left subtree.
        // Left subtree values must be smaller than root->val.
        root->left = build(A, i, root->val);

        // Build the right subtree.
        // Right subtree can contain values up to the
        // current subtree's bound.
        root->right = build(A, i, bound);

        return root;
    }
};