class Solution {
public:
vector<vector<int>>t;
int f(string &s1,string &s2,int n,int m){
    if(n==0||m==0)return 0;
    if(t[n][m]!=-1)return t[n][m];
    if(s1[n-1]==s2[m-1])return t[n][m]=1+f(s1,s2,n-1,m-1);
    return t[n][m]=max(f(s1,s2,n-1,m),f(s1,s2,n,m-1));
}
    int minInsertions(string &s1) {
        int n=s1.size();
        int m=n;
        t.assign(n+1,vector<int>(m+1,-1));
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return n-f(s1,s2,n,m);
    }
};