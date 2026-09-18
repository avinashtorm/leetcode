class Solution {
public:
void dfs(int i,int j,int k,int n,int m,vector<vector<int>>&a,vector<vector<int>>&visited,int colour){
    if(visited[i][j]==1)return;
    visited[i][j]=1;
    a[i][j]=colour;
    if(i>0&&a[i-1][j]==k)dfs(i-1,j,k,n,m,a,visited,colour);
    if(i<n-1&&a[i+1][j]==k)dfs(i+1,j,k,n,m,a,visited,colour);
    if(j>0&&a[i][j-1]==k)dfs(i,j-1,k,n,m,a,visited,colour);
    if(j<m-1&&a[i][j+1]==k)dfs(i,j+1,k,n,m,a,visited,colour);
}
    vector<vector<int>> floodFill(vector<vector<int>>&a, int sr, int sc, int colour) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        dfs(sr,sc,a[sr][sc],n,m,a,visited,colour);
        return a;
    }
};