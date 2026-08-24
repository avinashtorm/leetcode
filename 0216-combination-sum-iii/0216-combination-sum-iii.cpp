class Solution {
public:
void f(vector<int>&a,vector<vector<int>>&v,vector<int>v1,int k,int n,int i){
    if(n==0&&v1.size()==k){
        v.push_back(v1);
        return;
    }
    if(i==0)return;
    if(a[i-1]<=n){
        f(a,v,v1,k,n,i-1);
        v1.push_back(a[i-1]);
        f(a,v,v1,k,n-a[i-1],i-1);
    }
    else f(a,v,v1,k,n,i-1);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>v;
        vector<int>v1;
        f(a,v,v1,k,n,9);
        return v;
    }
};