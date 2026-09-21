class Solution {
public:
bool dfs(int c,int cc,vector<int>&v,vector<vector<int>>&a){
    v[c]=cc;
    for(int i=0;i<a[c].size();i++){
        if(v[a[c][i]]==cc)return false;
        if(v[a[c][i]]!=0)continue;
        if(cc==1)if(dfs(a[c][i],2,v,a)==false)return false;
        if(cc==2)if(dfs(a[c][i],1,v,a)==false)return false;
    }
    return true;
}
    bool isBipartite(vector<vector<int>>&a){
        int n=a.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
                if(v[i]!=0)continue;
                if(dfs(i,1,v,a)==false)return false;
        }
        return true;
    }
};