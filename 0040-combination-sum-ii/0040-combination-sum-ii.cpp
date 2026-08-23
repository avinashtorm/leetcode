class Solution {
public:
    void f(vector<int>&a,int t,vector<vector<int>>&v,int n,vector<int>&v1){
        if(t==0){
            v.push_back(v1);
            return;
        }
        if(n==0)return;

        if(a[n-1]<=t){
            v1.push_back(a[n-1]);
            f(a,t-a[n-1],v,n-1,v1);
            v1.pop_back();

            int k=n-1;
            while(k>0&&a[k-1]==a[n-1])k--;
            f(a,t,v,k,v1);
        }
        else{
            int k=n-1;
            while(k>0&&a[k-1]==a[n-1])k--;
            f(a,t,v,k,v1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>&a,int t){
        sort(a.begin(),a.end());
        vector<vector<int>>v;
        vector<int>v1;
        f(a,t,v,a.size(),v1);
        return v;
    }
};
//jab hum current 1 ko reject kar dete hain, toh baaki saare consecutive 1 ko bhi reject karke seedha 2 par chale jaate hain.