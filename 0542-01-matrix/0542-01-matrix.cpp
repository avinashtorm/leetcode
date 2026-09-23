class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&a) {
        int n=a.size(),m=a[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    q.push({{i,j},0});
                    dist[i][j]=0;
                }
            }
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto[x,y]=q.front();
            int x0=x.first,x1=x.second;
            dist[x0][x1]=y;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x0+dx[i];
                int ny=x1+dy[i];
                if(nx<n&&nx>=0&&ny<m&&ny>=0){
                    if(dist[nx][ny]!=INT_MAX)continue;
                    dist[nx][ny]=y+1;
                    q.push({{nx,ny},y+1});
                }
            }
        }
        return dist;
    }
};