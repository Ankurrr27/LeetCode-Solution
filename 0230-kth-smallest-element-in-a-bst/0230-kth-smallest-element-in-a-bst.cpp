class Solution {
public:

    int kthSmallest(TreeNode* root, int k) {
        
        // Vector to store nodes in inorder traversal
        vector<int> res;

        // Perform inorder traversal
        inorder(root, res);

        // Inorder traversal of a BST gives sorted order
        // So kth smallest element is at index k-1
        return res[k - 1];
    }

    void inorder(TreeNode* root, vector<int>& res) {

        // Base case: if there is no node, return
        if (root == NULL)
            return;

        // Visit the left subtree first
        inorder(root->left, res);

        // Store the current node's value
        res.push_back(root->val);

        // Visit the right subtree
        inorder(root->right, res);
    }
};