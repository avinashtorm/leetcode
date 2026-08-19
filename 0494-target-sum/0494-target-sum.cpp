class Solution {
public:
int f(vector<int>&a,int n,int s){
    if(n==0&&s==0)return 1;
    if(n==0)return 0;
    return f(a,n-1,s-a[n-1])+f(a,n-1,s+a[n-1]);
}
    int findTargetSumWays(vector<int>& a, int s) {
        return f(a,a.size(),s);
    }
};