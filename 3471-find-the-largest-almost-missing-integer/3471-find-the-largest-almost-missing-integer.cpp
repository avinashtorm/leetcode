class Solution {
public:
    int largestInteger(vector<int>& a, int k) {
        int n=a.size();
        int h[51];
        for(int j=0;j<=n-k;j++){
            unordered_map<int,int>mp;
        for(int i=j;i<j+k&&i<n;i++){
            if(mp.find(a[i])==mp.end()){
            h[a[i]]++;
            mp[a[i]]++;
            }
        }
        }
        int ans=-1;
        for(int i=0;i<51;i++){
            if(h[i]==1)ans=i;
        }
        return ans;
    }
};