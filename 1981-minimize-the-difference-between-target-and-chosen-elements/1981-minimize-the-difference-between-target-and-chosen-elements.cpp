class Solution {
public:
int t[5001][71];
    int f(vector<vector<int>>& a,int ta,int sum,int r){
        if(r==a.size())return abs(ta-sum);
        if(t[sum][r]!=-1)return t[sum][r];
        int ans=INT_MAX;
        for(int i=0;i<a[r].size();i++){
            int calans=f(a,ta,sum+a[r][i],r+1);
            ans=min(ans,calans);
        }
        return t[sum][r]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& a, int ta){
        int n=a.size();
        int m=a[0].size();
        memset(t,-1,sizeof(t));
        return f(a,ta,0,0);
    }
};