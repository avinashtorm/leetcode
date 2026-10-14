class Solution {
public:
    int trap(vector<int>&a) {
        int n=a.size();
        vector<int>l(n,0),r(n,0);
        for(int i=1;i<n;i++){
            if(l[i-1]<a[i-1])l[i]=a[i-1];
            else l[i]=l[i-1];
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1]<a[i+1])r[i]=a[i+1];
            else r[i]=r[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++)if(min(l[i],r[i])>a[i])ans+=(min(l[i],r[i])-a[i]);
        return ans;
    }
};