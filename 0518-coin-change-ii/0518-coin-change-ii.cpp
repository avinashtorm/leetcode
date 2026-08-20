class Solution {
  public:
  int t[301][5001];
  int f(vector<int>&a,int n,int s){
      if(s==0)return 1;
      if(s<0)return 0;
      if(n==0)return 0;
      if(t[n][s]!=-1)return t[n][s];
      if(s>=a[n-1])
      return t[n][s]=f(a,n,s-a[n-1])+f(a,n-1,s);
      return t[n][s]=f(a,n-1,s);
  }
    int change(int s,vector<int>&a) {
        memset(t,-1,sizeof(t));
        int n=a.size();
        return f(a,n,s);
    }
};
