class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>&a){
        int n=a.size();
        if(a[0][0]==1||a[n-1][n-1]==1)return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        dist[0][0]=1;
        int dx[]={0,0,1,-1,1,-1,1,-1};
        int dy[]={1,-1,0,0,-1,1,1,-1};
        int ans=INT_MAX;
        while(!q.empty()){
            auto [x,y]=q.front();
            int x1=x.first,x2=x.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx=x1+dx[i];
                int ny=x2+dy[i];
                if(nx<n&&nx>=0&&ny<n&&ny>=0){
                    if(a[nx][ny]==1||dist[nx][ny]<=y+1)continue;
                        q.push({{nx,ny},y+1});
                        dist[nx][ny]=y+1;
                }
            }
        }
        return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1];
    }
};