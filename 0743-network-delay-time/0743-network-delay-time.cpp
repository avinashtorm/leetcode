class Solution {
public:
    int networkDelayTime(vector<vector<int>>&edges, int n, int src){
        vector<vector<pair<int,int>>>a(n+1);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            a[u].push_back({v,wt});
        }
        set<pair<int,int>>st;
        vector<int>time(n+1,INT_MAX);
        time[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto [d,u]=*st.begin();
            st.erase(st.begin());
            for(auto &[v,wt]:a[u]){
                if(d+wt<time[v]){
                    time[v]=d+wt;
                    st.insert({time[v],v});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<n+1;i++){
            if(time[i]==INT_MAX)return -1;
            ans=max(ans,time[i]);
        }
        return ans;
    }
};