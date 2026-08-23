class Solution {
public:
void f(vector<int>&a,vector<vector<int>>&v,vector<int>v1,int n){
    if(n==0){
        v.push_back(v1);
        return;
    }
    f(a,v,v1,n-1);
    v1.push_back(a[n-1]);
    f(a,v,v1,n-1);
}
    vector<vector<int>> subsets(vector<int>&a) {
        vector<vector<int>>v;
        vector<int>v1;
        int n=a.size();
        f(a,v,v1,n);
        return v;
    }
};