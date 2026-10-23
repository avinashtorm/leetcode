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
        int id=0;
TreeNode* build(vector<int>&preorder,vector<int>&inorder,int l,int r){
    if(l>r)return NULL;
    TreeNode* root=new TreeNode(preorder[id++]);
    int mid=mp[root->val];
    root->left=build(preorder,inorder,l,mid-1);
    root->right=build(preorder,inorder,mid+1,r);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        id=0;
        mp.clear();
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
        return build(preorder,inorder,0,inorder.size()-1);
    }
};
