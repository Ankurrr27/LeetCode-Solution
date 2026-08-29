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

    // Store the parent of every node so that we can move
    // from a node to its parent during the BFS.
    void markParent(TreeNode* root, map<TreeNode*, TreeNode*>& parent_track, TreeNode* target){ 
        
        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()){ 
            TreeNode* curr = q.front(); 
            q.pop(); 

            // Store current node as the parent of its left child
            if(curr->left){ 
                parent_track[curr->left] = curr; 
                q.push(curr->left); 
            } 

            // Store current node as the parent of its right child
            if(curr->right){ 
                parent_track[curr->right] = curr; 
                q.push(curr->right); 
            } 
        } 
    } 


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) { 
        
        // Map each node to its parent
        map<TreeNode*, TreeNode*> parent_track; 
        markParent(root, parent_track, target); 

        // Keeps track of nodes that have already been visited
        // to avoid traversing the same node again.
        map<TreeNode*, bool> visited; 

        // BFS starting from the target node
        queue<TreeNode*> q; 
        q.push(target); 
        visited[target] = true; 

        int dist = 0; 

        while(!q.empty()){ 
            
            int n = q.size(); 

            // If current distance is k, all nodes currently
            // in the queue are exactly k distance away.
            if(dist++ == k) break; 

            // Process all nodes at the current distance
            for(int i = 0; i < n; i++){ 
                
                TreeNode* curr = q.front(); 
                q.pop(); 

                // Move to the left child
                if(curr->left && !visited[curr->left]){ 
                    q.push(curr->left); 
                    visited[curr->left] = true; 
                } 

                // Move to the right child
                if(curr->right && !visited[curr->right]){ 
                    q.push(curr->right); 
                    visited[curr->right] = true; 
                } 

                // Move upward to the parent
                if(parent_track[curr] && !visited[parent_track[curr]]){ 
                    q.push(parent_track[curr]); 
                    visited[parent_track[curr]] = true; 
                } 
            } 
        } 

        // All nodes remaining in the queue are at distance k
        vector<int> res; 

        while(!q.empty()){ 
            TreeNode* curr = q.front(); 
            q.pop(); 
            res.push_back(curr->val); 
        } 

        return res; 
    } 
};

