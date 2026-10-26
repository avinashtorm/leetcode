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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
        queue<pair<TreeNode*,pair<int,int>>>q;    //{node,{horiz_dist,level}}
        unordered_map<int,unordered_map<int,multiset<int>>>mp;   //hd->(level->{elements..})
        q.push({root,{0,0}});
        int mnhd=0,mxhd=0,mxl=0;
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            TreeNode* node=a.first;
            int hd=a.second.first,lvl=a.second.second;
            mnhd=min(mnhd,hd);
            mxhd=max(mxhd,hd);
            mxl=max(lvl,mxl);
            mp[hd][lvl].insert(node->val);
            if(node->left)q.push({node->left,{hd-1,lvl+1}});
            if(node->right)q.push({node->right,{hd+1,lvl+1}});
        }
        vector<vector<int>>v(mxhd-mnhd+1);
        for(int i=mnhd;i<=mxhd;i++){
            for(int j=0;j<=mxl;j++){
                for(auto &e:mp[i][j]){
                    v[i-mnhd].push_back(e);
                }
            }
        }
        return v;
    }
};