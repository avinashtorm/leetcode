class Solution {
public:
vector<vector<int>>t;
int f(string &s1,string &s2,int n,int m){
    if(n==0||m==0)return 0;
    if(t[n][m]!=-1)return t[n][m];
    if(s1[n-1]==s2[m-1])return t[n][m]=1+f(s1,s2,n-1,m-1);
    return t[n][m]=max(f(s1,s2,n,m-1),f(s1,s2,n-1,m));
}
    bool isSubsequence(string &s1, string &s2) {
        int n=s1.size(),m=s2.size();
        t.assign(n+1,vector<int>(m+1,-1));
        int lcs=f(s1,s2,n,m);
        return lcs==n;
            }
};