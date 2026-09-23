class Solution {
public:
int find(int i,vector<int>&parent){
    if(i==parent[i])return i;
    return parent[i]=find(parent[i],parent);
}
void Union(int i,int j,vector<int>&parent,vector<int>&rank){
    int x=find(i,parent);
    int y=find(j,parent);
    if(x==y)return;
    if(rank[i]>rank[j]){
        parent[y]=x;
    }else if(rank[i]<rank[j]){
        parent[x]=y;
    }else{
        parent[x]=y;
        rank[y]++;
    }
}
    bool equationsPossible(vector<string>&a) {
        int n=a.size();
        vector<int>parent(26);
        vector<int>rank(26,0);
        for(int i=0;i<26;i++)parent[i]=i;
        for(int i=0;i<n;i++)if(a[i][1]=='=')Union(a[i][0]-'a',a[i][3]-'a',parent,rank);
        for(int i=0;i<n;i++){
            if(a[i][1]=='!'){
                if(find(a[i][0]-'a',parent)==find(a[i][3]-'a',parent))return false;
            }
        }
        return true;

    }
};