class Solution {
public:

    // Deletes the node having value 'key'
    // and returns the new root of the tree.
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Empty tree
        if (root == NULL)
            return NULL;


        // If the root itself is the node to delete,
        // let helper() handle the deletion.
        if (root->val == key)
            return helper(root);


        // Keep the original root safe.
        // 'root' will move while searching.
        TreeNode* dummy = root;


        // Search for the node using BST property.
        while (root != NULL) {

            // key is smaller, so search in the left subtree.
            if (root->val > key) {

                // Check if the left child is the node to delete.
                if (root->left != NULL &&
                    root->left->val == key) {

                    // Delete the left child and connect
                    // its replacement to root->left.
                    root->left = helper(root->left);
                    break;
                }

                // Continue searching on the left.
                else {
                    root = root->left;
                }
            }

            // key is greater, so search in the right subtree.
            else {

                // Check if the right child is the node to delete.
                if (root->right != NULL &&
                    root->right->val == key) {

                    // Delete the right child and connect
                    // its replacement to root->right.
                    root->right = helper(root->right);
                    break;
                }

                // Continue searching on the right.
                else {
                    root = root->right;
                }
            }
        }

        // Return the original root of the tree.
        return dummy;
    }


    // Deletes the given node and returns
    // the root that should replace it.
    TreeNode* helper(TreeNode* root) {

        // Case 1:
        // No left child.
        //
        // Replace this node with its right child.
        if (root->left == NULL) {
            return root->right;
        }


        // Case 2:
        // No right child.
        //
        // Replace this node with its left child.
        else if (root->right == NULL) {
            return root->left;
        }


        // Case 3:
        // Node has both left and right children.

        // Save the right subtree.
        TreeNode* rightChild = root->right;


        // Find the rightmost node of the left subtree.
        // This is the inorder predecessor.
        TreeNode* lastRight = findLastRight(root->left);


        // Attach the original right subtree
        // to the rightmost node of the left subtree.
        lastRight->right = rightChild;


        // The left subtree now becomes
        // the replacement for the deleted node.
        return root->left;
    }


    // Finds the rightmost node of a subtree.
    TreeNode* findLastRight(TreeNode* root) {

        // If there is no right child,
        // this is the rightmost node.
        if (root->right == NULL) {
            return root;
        }

        // Keep moving right.
        return findLastRight(root->right);
    }
};