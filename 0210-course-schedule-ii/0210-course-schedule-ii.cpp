class Solution {
public:
void dfs(int c,queue<int>&q,vector<int>&v,vector<vector<int>>&a,bool &invalid){
    if(v[c]==1){
        invalid=true;
        return;
    }
    v[c]=1;
    for(int i=0;i<a[c].size();i++){
        if(v[a[c][i]]==2)continue;
        dfs(a[c][i],q,v,a,invalid);
    }
    q.push(c);
    v[c]=2;
}
    vector<int> findOrder(int n,vector<vector<int>>&e){
        vector<vector<int>>a(n);
        for(auto &x:e)a[x[0]].push_back(x[1]);
        vector<int>v(n,0);
        queue<int>q;
        bool invalid=false;
        for(int i=0;i<n;i++){
            if(v[i]==2)continue;
            dfs(i,q,v,a,invalid);
        }
        vector<int>ans;
        if(invalid)return ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};