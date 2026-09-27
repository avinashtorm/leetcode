class Solution {
public:
    int minimumEffortPath(vector<vector<int>>&a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,0}});   
        dist[0][0]=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!st.empty()){
            auto it=st.begin();
            auto [d,ind]=*it;
            auto [x,y]=ind;
            st.erase(it);
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int eff=abs(a[nx][ny]-a[x][y]);
                    eff=max(eff,d);
                    if(eff<dist[nx][ny]){
                        if(dist[nx][ny]!=INT_MAX)st.erase({dist[nx][ny],{nx,ny}});
                        dist[nx][ny]=eff;
                        st.insert({eff,{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
