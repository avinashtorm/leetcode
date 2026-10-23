
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)return v;
        queue<TreeNode*>q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>a(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(c%2==0)a[i]=node->val;
                else a[n-1-i]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            v.push_back(a);
            c++;
        }
        return v;
    }
};
