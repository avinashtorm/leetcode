class Solution {
public:
int t[201][20001];
bool f(vector<int>&a,int n,int s){
    if(s==0)return true;
    if(s<0)return false;
    if(n==0)return false;
    if(t[n][s]!=-1)return t[n][s];
    if(a[n-1]<=s)return t[n][s]=f(a,n-1,s-a[n-1])||f(a,n-1,s);
    else return t[n][s]=f(a,n-1,s);
}
    bool canPartition(vector<int>& a) {
        memset(t,-1,sizeof(t));
        int s=accumulate(a.begin(),a.end(),0);
        if(s&1)return false;
        s/=2;
        int n=a.size();
        return f(a,n,s);
    }
};