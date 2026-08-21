class Solution {
public:
vector<vector<int>>t;
string s="";
void f(string &s1,string &s2,int n,int m){
    if(n==0&&m==0){
        return;
    }else if(n==0){
        s+=s2[m-1];
        f(s1,s2,n,m-1);
    }else if(m==0){
        s+=s1[n-1];
        f(s1,s2,n-1,m);
    }else if(s1[n-1]==s2[m-1]){
        s+=s1[n-1];
        f(s1,s2,n-1,m-1);
    }
    else if(t[n-1][m]>=t[n][m-1]){
        s+=s1[n-1];
        f(s1,s2,n-1,m);
    }else if(t[n-1][m]<t[n][m-1]){
        s+=s2[m-1];
        f(s1,s2,n,m-1);
    }
}
    string shortestCommonSupersequence(string &s1, string &s2) {
        int n=s1.size(),m=s2.size();
        t.assign(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        f(s1,s2,n,m);
        reverse(s.begin(),s.end());
        return s;
    }
};

