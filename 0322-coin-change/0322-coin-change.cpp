class Solution {
  public:
  vector<vector<int>>t;
  int f(vector<int>&a,int n,int s){
      if(s==0)return 0;
      if(s<0)return INT_MAX-1;
      if(n==0)return INT_MAX-1;
      if(t[n][s]!=-1)return t[n][s];
      if(s>=a[n-1])return t[n][s]=min(1+f(a,n,s-a[n-1]),f(a,n-1,s));
      return t[n][s]=f(a,n-1,s);
  }
    int coinChange(vector<int> &a, int s) {
        int n=a.size();
        t.assign(n + 1, vector<int>(s + 1, -1));
        int k=f(a,n,s);
        if(k==INT_MAX-1)return -1;
        return k;
    }
};
