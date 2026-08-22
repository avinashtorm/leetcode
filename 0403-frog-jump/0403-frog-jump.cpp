class Solution {
public:
vector<vector<int>>t;
unordered_map<int,int>pos;
bool f(vector<int>&a,int c,int j,int &n){
    if(c==n-1)return true;
    if(t[c][j]!=-1)return t[c][j];
    int b1=false,b2=false,b3=false;
    if(j>1&&binary_search(a.begin(),a.end(),a[c]+j-1))b1=f(a,pos[a[c]+j-1],j-1,n);
    if(binary_search(a.begin(),a.end(),a[c]+j))b2=f(a,pos[a[c]+j],j,n);
    if(binary_search(a.begin(),a.end(),a[c]+j+1))b3=f(a,pos[a[c]+j+1],j+1,n);
    return t[c][j]=b1||b2||b3;
}
    bool canCross(vector<int>& a) {
        if(a[1]-a[0]!=1)return false;
        int n=a.size();
        t.assign(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            pos[a[i]]=i;
        }
        return f(a,1,1,n);
    }
};