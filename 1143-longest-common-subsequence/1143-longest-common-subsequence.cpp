class Solution {
public:
vector<vector<int>>t;
int f(string &s1, string &s2,int n,int m){
    if(n==0||m==0)return 0;
    if(t[n][m]!=-1)return t[n][m];
    if(s1[n-1]==s2[m-1])return t[n][m]=1+f(s1,s2,n-1,m-1);
    else return t[n][m]=max(f(s1,s2,n,m-1),f(s1,s2,n-1,m));
}
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        t.assign(n+1,vector<int>(m+1,-1));
        return f(s1,s2,n,m);
    }
};
























//  for(int i=0;i<=n;i++)t[i][0]=0;
//         for(int j=0;j<=m;j++)t[0][j]=0;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1]){
//                     t[i][j]=1+t[i-1][j-1];
//                 }
//                 else{
//                     t[i][j]=max(t[i][j-1],t[i-1][j]);
//                 }
//             }
//         }
//         return t[n][m];