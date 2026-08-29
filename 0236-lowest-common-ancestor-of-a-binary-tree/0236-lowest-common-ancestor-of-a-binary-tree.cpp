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
    bool path(TreeNode* node,vector<TreeNode*>& route, TreeNode* target){
        if(node==NULL) return false;

        route.push_back(node);

        if(node==target) return true;

        if(path(node->left,route,target) || path(node->right,route,target)) return true;

        route.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> Pathp;
        vector<TreeNode*> Pathq;
        TreeNode* ans = root;
        path(root,Pathp,p);
        path(root,Pathq,q);

        int n = min(Pathp.size(), Pathq.size());
        for(int i=0;i<n;i++){
            if(Pathp[i]==Pathq[i]) ans=Pathp[i];
        }
        return ans;
    }
};

