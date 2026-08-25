class Solution {
public:
    int f(vector<int>&a,int t,int n,int m){
        if(t==0)return m;
        if(n==0)return INT_MIN;
        if(a[n-1]<=t){
            return max(f(a,t-a[n-1],n,m*a[n-1]),
                       f(a,t,n-1,m));
        }
        else{
            return f(a,t,n-1,m);
        }
    }

    int integerBreak(int n){
        vector<int>a;
        for(int i=1;i<n;i++){
            a.push_back(i);
        }
        return f(a,n,n-1,1);
    }
};