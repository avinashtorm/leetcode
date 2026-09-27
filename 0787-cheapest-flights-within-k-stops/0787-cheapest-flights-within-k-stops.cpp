class Solution {
public:
int findCheapestPrice(int n,vector<vector<int>>&fl,int src,int dest,int k){
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp=dist;
            for(auto &f:fl){
                int u=f[0];
                int v=f[1];
                int wt=f[2];
                if(dist[u]!=INT_MAX){
                    temp[v]=min(temp[v],dist[u]+wt);
                }
            }
            dist=temp;
        }
        if(dist[dest]==INT_MAX)return -1;
        return dist[dest];
    }
};