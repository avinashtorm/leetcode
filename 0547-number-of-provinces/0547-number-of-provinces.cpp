class Solution {
public:
void dfs(int c,int n,vector<bool>&visited,vector<vector<int>>&a){
    visited[c]=true;
    for(int i=0;i<n;i++){
        if(a[c][i]==0)continue;
        if(visited[i]==true)continue;
        dfs(i,n,visited,a);
    }
}
    int findCircleNum(vector<vector<int>>&a) {
        int n=a.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==true)continue;
            dfs(i,n,visited,a);
            count++;
        }
        return count;
    }
};