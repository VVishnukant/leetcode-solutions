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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(levels(root->left),levels(root->right));
    }
    void LR_nthlevel(TreeNode* root,int curr,int level,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        LR_nthlevel(root->left,curr+1,level,v);
        LR_nthlevel(root->right,curr+1,level,v);
    }
    void RL_nthlevel(TreeNode* root,int curr,int level,vector<int>&v){
        if(root==NULL) return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        RL_nthlevel(root->right,curr+1,level,v);
        RL_nthlevel(root->left,curr+1,level,v);
    }
    void traversal(TreeNode* root,vector<vector<int>>&ans){
        if(root==NULL) return;
        int n = levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            if(i%2!=0) LR_nthlevel(root, 1,i,v);
            else RL_nthlevel(root,1,i,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        traversal(root,ans);
        return ans;
    }
};