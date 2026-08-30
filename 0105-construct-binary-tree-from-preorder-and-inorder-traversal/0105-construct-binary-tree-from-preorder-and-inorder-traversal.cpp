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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store each value's index in inorder
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Start with the complete preorder and inorder arrays.
        //
        // IMPORTANT:
        // preEnd and inEnd are inclusive,
        // so we use size() - 1.
        return build(
            preorder,
            0,
            preorder.size() - 1,
            inorder,
            0,
            inorder.size() - 1,
            inMap
        );
    }


    TreeNode* build(
        vector<int>& preorder,
        int preStart,
        int preEnd,
        vector<int>& inorder,
        int inStart,
        int inEnd,
        map<int, int>& inMap
    ) {

        // No elements available for this subtree
        if (preStart > preEnd || inStart > inEnd)
            return NULL;


        // First element of preorder is the root
        TreeNode* root = new TreeNode(preorder[preStart]);


        // Find the root's position in inorder
        int inRoot = inMap[root->val];


        // Number of nodes in the left subtree
        int numsLeft = inRoot - inStart;


        // Build left subtree
        //
        // Preorder:
        // root | left subtree | right subtree
        //
        // So left subtree starts at preStart + 1
        // and contains numsLeft nodes.
        root->left = build(
            preorder,
            preStart + 1,
            preStart + numsLeft,
            inorder,
            inStart,
            inRoot - 1,
            inMap
        );


        // Build right subtree
        //
        // Left subtree has numsLeft nodes,
        // so right subtree starts after:
        //
        // root + left subtree
        //
        root->right = build(
            preorder,
            preStart + numsLeft + 1,
            preEnd,
            inorder,
            inRoot + 1,
            inEnd,
            inMap
        );


        return root;
    }
};