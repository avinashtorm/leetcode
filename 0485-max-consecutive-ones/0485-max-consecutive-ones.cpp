class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>&a) {
        int i=0,j=0,n=a.size(),ans=0;
        queue<int>q;
        while(j<n){
            if(a[j]==1)q.push(1);
            ans=max(ans,int(q.size()));
            if(a[j]==0){
                while(!q.empty())q.pop();
            }
            j++;
        }
        return ans;
    }
};