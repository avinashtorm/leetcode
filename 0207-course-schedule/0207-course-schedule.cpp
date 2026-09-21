class Solution {
public:
bool dfs(int c,vector<int>&v,vector<vector<int>>&a){
    if(v[c]==1)return true;
    if(v[c]==2)return false;
    v[c]=1;
    for(int i=0;i<a[c].size();i++){
        if(dfs(a[c][i],v,a))return true;
    }
    v[c]=2;
    return false;
}
    bool canFinish(int n, vector<vector<int>>&e) {
        vector<vector<int>>a(n);
        for(auto &x:e)a[x[0]].push_back(x[1]);
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(dfs(i,v,a))return false;
        }
        return true;
    }
};