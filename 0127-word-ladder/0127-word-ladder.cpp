class Solution {
public:
bool dif_1(string s1,string s2){
    int c=0;
    for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i])c++;
    if(c==1)return true;
    return false;
}
    int ladderLength(string beg, string end, vector<string>&words){
        words.push_back(beg);
        bool f=true;
        for(auto &e:words)if(e==end)f=false;
        if(f)return 0;
        int n=words.size();
        int bindex=n-1,eindex;
        vector<vector<int>>a(n);
        for(int i=0;i<n;i++){
            if(words[i]==end)eindex=i;
            for(int j=i+1;j<n;j++){
                if(dif_1(words[i],words[j])){
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(bindex);
        dist[bindex]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto &v:a[u]){
                if(1+dist[u]<dist[v]){
                    dist[v]=1+dist[u];
                    q.push(v);
                }
            }
        }
        if(dist[eindex]==INT_MAX)return 0;
        return dist[eindex];
    }
};