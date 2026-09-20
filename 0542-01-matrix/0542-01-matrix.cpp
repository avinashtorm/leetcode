class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>&a){
        int n=a.size(),m=a[0].size();
        vector<vector<int>>dist;
        dist.assign(n,vector<int>(m,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
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
            int k=q.size();
            while(k--){
            auto[g,h]=q.front();
            int x=g.first,y=g.second;
            q.pop();
            for(int i=0;i<4;i++){
                if(x+dx[i]<n&&x+dx[i]>=0&&y+dy[i]<m&&y+dy[i]>=0){
                    if(dist[x+dx[i]][y+dy[i]]!=INT_MAX)continue;
                    q.push({{x+dx[i],y+dy[i]},h+1});
                    dist[x+dx[i]][y+dy[i]]=min(dist[x+dx[i]][y+dy[i]],h+1);
                }
            }

            }
        }
        return dist;
    }
};