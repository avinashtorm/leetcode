class Solution {
public:
    int numEnclaves(vector<vector<int>>&a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>out(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)if(a[i][0]==1){
            out[i][0]=1;
            q.push({i,0});
        }
        for(int i=0;i<n;i++)if(a[i][m-1]==1){
            out[i][m-1]=1;
            q.push({i,m-1});
        }
        for(int i=0;i<m;i++)if(a[0][i]==1){
            out[0][i]=1;
            q.push({0,i});
        }
        for(int i=0;i<m;i++)if(a[n-1][i]==1){
            out[n-1][i]=1;
            q.push({n-1,i});
        }
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n&&nx>=0&&ny<m&&ny>=0){
                    if(a[nx][ny]==0)continue;
                    if(out[nx][ny]==1)continue;
                    q.push({nx,ny});
                    out[nx][ny]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1&&out[i][j]==0)count++;
            }
        }
        return count;
    }
};