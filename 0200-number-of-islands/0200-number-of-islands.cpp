class Solution {
public:
void traverse(int i,int j,int n,int m,vector<vector<int>>&visited,vector<vector<char>>&a){
    if(visited[i][j]==1)return;
    visited[i][j]=1;
    if(i<n-1&&a[i+1][j]=='1')traverse(i+1,j,n,m,visited,a);
    if(i>0&&a[i-1][j]=='1')traverse(i-1,j,n,m,visited,a);
    if(j<m-1&&a[i][j+1]=='1')traverse(i,j+1,n,m,visited,a);
    if(j>0&&a[i][j-1]=='1')traverse(i,j-1,n,m,visited,a);
}
    int numIslands(vector<vector<char>>&a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==1)continue;
                if(a[i][j]=='0')continue;
                traverse(i,j,n,m,visited,a);
                count++;
            }
        }
        return count;
    }
};