/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int leftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }
    int rightHeight(TreeNode* root) {// TC : O(logN) = O(height)
        int height = 0;

        while (root) {
            height++;
            root = root->right;
        }

        return height;
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if (rh == lh) {
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
