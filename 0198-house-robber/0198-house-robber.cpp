class Solution {
public:
vector<int>t;
int f(vector<int>&a,int i,int n){
    if(i>=n)return 0;
    if(t[i]!=-1)return t[i];
    return t[i]=a[i]+max(f(a,i+2,n),f(a,i+3,n));
}
    int rob(vector<int>&a) {
        int n=a.size();
        t.assign(n+1,-1);
        if(n==1)return a[0];
        if(n==2)return max(a[0],a[1]);
        if(n==3)return max(max(max(a[0],a[1]),a[2]),f(a,0,n));
        return max(f(a,0,n),f(a,1,n));
    }
};