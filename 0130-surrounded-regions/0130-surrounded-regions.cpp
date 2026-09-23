class Solution {
public:
    void solve(vector<vector<char>>&a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>safe(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)if(a[0][i]=='O'){
            q.push({0,i});
            safe[0][i]=1;
        }
        for(int i=0;i<n;i++)if(a[i][0]=='O'){
            q.push({i,0});
            safe[i][0]=1;
        }
        for(int i=0;i<m;i++)if(a[n-1][i]=='O'){
            q.push({n-1,i});
            safe[n-1][i]=1;
        }
        for(int i=0;i<n;i++)if(a[i][m-1]=='O'){
            q.push({i,m-1});
            safe[i][m-1]=1;
        }
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n&&nx>=0&&ny<m&&ny>=0){
                    if(a[nx][ny]=='X')continue;
                    if(safe[nx][ny]==1)continue;
                    safe[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='O'&&safe[i][j]==0)a[i][j]='X';
            }
        }
    }
};