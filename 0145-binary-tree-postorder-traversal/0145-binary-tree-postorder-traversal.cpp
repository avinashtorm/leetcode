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
void tr(vector<int>&v,TreeNode* node){
    if(!node)return;
    tr(v,node->left);
    tr(v,node->right);
    v.push_back(node->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        tr(v,root);
        return v;
    }
};