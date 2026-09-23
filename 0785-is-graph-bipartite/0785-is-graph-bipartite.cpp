class Solution {
public:
    bool isBipartite(vector<vector<int>>&a) {
        int n=a.size();
        vector<int>v(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(v[i]!=0)continue;
            q.push(i);
            v[i]=1;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(int j=0;j<a[x].size();j++){
                    if(v[x]==v[a[x][j]])return false;
                    if(v[a[x][j]]!=0)continue;
                    q.push(a[x][j]);
                    v[a[x][j]]=3-v[x];
                }
            }
        }
        return true;
    }
};