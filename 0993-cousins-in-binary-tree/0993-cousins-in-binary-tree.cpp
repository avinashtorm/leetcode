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
TreeNode* parent(TreeNode* root,int n){
    if(!root)return NULL;
    if((root->left&&root->left->val==n)||(root->right&&root->right->val==n))return root;
    TreeNode* l=parent(root->left,n);
    if(l)return l;
    return parent(root->right,n);
}
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *px=parent(root,x),*py=parent(root,y);
        if(px==py)return false;
        queue<TreeNode*>q;
        int depth=0,dx=-1,dy=-1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                if(node->val==x)dx=depth;
                if(node->val==y)dy=depth;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(dx!=-1&&dx==dy)return true;
            depth++;
        }
        return false;
    }
};