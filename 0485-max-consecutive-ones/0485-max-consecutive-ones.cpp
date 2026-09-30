class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>&a) {
        int i=0,j=0,n=a.size(),ans=0,cnt=0;
        queue<int>q;
        while(j<n){
            if(a[j]==1)cnt++;
            ans=max(ans,cnt);
            if(a[j]==0)cnt=0;
            j++;
        }
        return ans;
    }
};