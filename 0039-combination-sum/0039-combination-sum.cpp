class Solution {
public:
    void f(vector<int>&a,int t,vector<vector<int>>&v,int n,vector<int>v1){
        if(t==0){
            v.push_back(v1);
            return;
        }
        if(n==0)return;
        if(a[n-1]<=t){
            f(a,t,v,n-1,v1);
            v1.push_back(a[n-1]);
            f(a,t-a[n-1],v,n,v1);
        }
        else f(a,t,v,n-1,v1);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>>v;
        vector<int>v1;
        int n=a.size();
        f(a,t,v,n,v1);
        return v;
    }
};