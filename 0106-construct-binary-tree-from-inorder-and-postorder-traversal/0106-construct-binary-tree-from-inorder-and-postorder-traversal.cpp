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
        unordered_map<int,int>mp;
        int id;
TreeNode* build(vector<int>&inorder,vector<int>&postorder,int l,int r){
    if(l>r)return NULL;
    TreeNode* root=new TreeNode(postorder[id--]);
    int mid=mp[root->val];
    root->right=build(inorder,postorder,mid+1,r);
    root->left=build(inorder,postorder,l,mid-1);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        id=inorder.size()-1;
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1);
    }
};