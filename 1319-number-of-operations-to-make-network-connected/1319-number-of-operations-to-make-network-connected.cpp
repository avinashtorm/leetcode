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
    if(rank[x]>rank[y]){
        parent[y]=x;
    }
    else if(rank[x]<rank[y]){
        parent[x]=y;
    }else{
        parent[y]=x;
        rank[x]++;
    }
}
    int makeConnected(int n, vector<vector<int>>&a){
        int c=a.size(),buffer=0;
        int dc=n;
        vector<int>parent(n);
    for(int i=0;i<n;i++)parent[i]=i;
    vector<int>rank(n,0);
        for(int i=0;i<c;i++){
            if(find(a[i][0],parent)==find(a[i][1],parent))buffer++;
            else{
                Union(a[i][0],a[i][1],parent,rank);
                dc--;
            } 
        }
        if(buffer>=dc-1)return dc-1;
        else return -1;
    }
};