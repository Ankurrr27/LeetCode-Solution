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

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // First element of preorder is always the root
        TreeNode* root = new TreeNode(preorder[0]);

        int i = 1;

        // Find the first element greater than root
        // Everything before it belongs to the left subtree
        while (i < preorder.size() && preorder[i] < root->val) {
            i++;
        }

        // Elements before i are the left subtree
        vector<int> left(preorder.begin() + 1, preorder.begin() + i);

        // Elements from i onwards are the right subtree
        vector<int> right(preorder.begin() + i, preorder.end());

        // Recursively construct left and right subtrees
        if (!left.empty())
            root->left = bstFromPreorder(left);

        if (!right.empty())
            root->right = bstFromPreorder(right);

        return root;
    }
};