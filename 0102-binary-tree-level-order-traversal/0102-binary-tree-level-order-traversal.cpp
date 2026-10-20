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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>v;
        q.push(root);
        while(!q.empty()){
           vector<int>a;
           queue<TreeNode*>q1;
           while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!node)continue;
            a.push_back(node->val);
            q1.push(node->left);
            q1.push(node->right);
           }
           if(a.size()>0)v.push_back(a);
           q=q1;
        }
        return v;
    }
};