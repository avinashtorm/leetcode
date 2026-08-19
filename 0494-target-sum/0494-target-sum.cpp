class Solution {
public:
  int t[21][2001];
  int f(vector<int>&a,int n,int s1,int s,int d){
      if(n==0&&s1==d)return 1;
      if(n==0)return 0;
      if(t[n][s1+1000]!=-1)return t[n][s1+1000];
      return t[n][s1+1000]=f(a,n-1,s1+a[n-1],s,d)+f(a,n-1,s1-a[n-1],s,d);
  }
    int findTargetSumWays(vector<int>& a, int d) {
        memset(t,-1,sizeof(t));
        int s=accumulate(a.begin(),a.end(),0);
        int n=a.size();
        return f(a,n,0,s,d);
    }
};