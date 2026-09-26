class Solution {
public:
bool dif_1(string s1,string s2){
    int c=0;
    for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i])c++;
    if(c==1)return true;
    return false;
}
void dfs(int u,int bindex,vector<vector<int>>&parent,vector<int>&path,vector<string>&words,vector<vector<string>>&ans){
    if(u==bindex){
        vector<string>temp;
        for(int i=path.size()-1;i>=0;i--)
            temp.push_back(words[path[i]]);
        ans.push_back(temp);
        return;
    }
    for(auto &p:parent[u]){
        path.push_back(p);
        dfs(p,bindex,parent,path,words,ans);
        path.pop_back();
    }
}
vector<vector<string>> findLadders(string beg,string end,vector<string>&words){
    vector<vector<string>>ans;
    words.push_back(beg);
    bool f=true;
    for(auto &e:words)if(e==end)f=false;
    if(f)return ans;
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
    vector<vector<int>>parent(n);
    queue<int>q;
    q.push(bindex);
    dist[bindex]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &v:a[u]){
            if(1+dist[u]<dist[v]){
                dist[v]=1+dist[u];
                parent[v].clear();
                parent[v].push_back(u);
                q.push(v);
            }
            else if(1+dist[u]==dist[v]){
                parent[v].push_back(u);
            }
        }
    }
    if(dist[eindex]==INT_MAX)return ans;
    vector<int>path;
    path.push_back(eindex);
    dfs(eindex,bindex,parent,path,words,ans);
    return ans;
}
};