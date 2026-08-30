class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Store value -> index in inorder
        // so we can find the root position quickly.
        unordered_map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Start with the complete arrays.
        return build(
            inorder,
            0,
            inorder.size() - 1,
            postorder,
            0,
            postorder.size() - 1,
            inMap
        );
    }


private:

    TreeNode* build(
        vector<int>& inorder,
        int inStart,
        int inEnd,
        vector<int>& postorder,
        int postStart,
        int postEnd,
        unordered_map<int, int>& inMap
    ) {

        // No elements left.
        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }


        // Postorder:
        //
        // LEFT -> RIGHT -> ROOT
        //
        // Therefore, the last element is the root.
        int rootValue = postorder[postEnd];

        TreeNode* root = new TreeNode(rootValue);


        // Find root's position in inorder.
        int inRoot = inMap[rootValue];


        // Number of nodes in the left subtree.
        int leftSize = inRoot - inStart;


        // ---------------- LEFT SUBTREE ----------------
        //
        // Inorder:
        // LEFT | ROOT | RIGHT
        //
        // Therefore:
        // left = inStart ... inRoot - 1
        //
        // In postorder:
        // LEFT | RIGHT | ROOT
        //
        // Left subtree has 'leftSize' nodes.
        root->left = build(
            inorder,
            inStart,
            inRoot - 1,
            postorder,
            postStart,
            postStart + leftSize - 1,
            inMap
        );


        // ---------------- RIGHT SUBTREE ----------------
        //
        // Right subtree starts after all left subtree nodes.
        //
        // Root is at postEnd, so right subtree ends at postEnd - 1.
        root->right = build(
            inorder,
            inRoot + 1,
            inEnd,
            postorder,
            postStart + leftSize,
            postEnd - 1,
            inMap
        );


        return root;
    }
};