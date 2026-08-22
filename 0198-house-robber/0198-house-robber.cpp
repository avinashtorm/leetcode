class Solution{
public:
vector<int>t;
int f(vector<int>&a,int i,int n){
    if(i>=n)return 0;
    if(t[i]!=-1)return t[i];
    return t[i]=max(a[i]+f(a,i+2,n),f(a,i+1,n));
}
int rob(vector<int>&a){
    int n=a.size();
    t.assign(n,-1);
    return f(a,0,n);
}
};