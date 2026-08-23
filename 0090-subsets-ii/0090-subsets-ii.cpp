class Solution {
public:
void f(vector<int>&a,vector<vector<int>>&v,vector<int>v1,int n){
    if(n==0){
        v.push_back(v1);
        return;
    }
    v1.push_back(a[n-1]);
    f(a,v,v1,n-1);
    v1.pop_back();
    int k=n-1;
    while(k>0&&a[k-1]==a[n-1])k--;
    f(a,v,v1,k);
}
    vector<vector<int>> subsetsWithDup(vector<int>&a) {
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>>v;
        vector<int>v1;
        f(a,v,v1,n);
        return v;
    }
};