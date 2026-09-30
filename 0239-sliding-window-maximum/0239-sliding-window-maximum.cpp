class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>&a, int k) {
        int i=0,j=0,n=a.size(),mx=INT_MIN;
        deque<int>q;
        vector<int>v;
        while(j<n){
            while(!q.empty()&&q.back()<a[j])q.pop_back();
            q.push_back(a[j]);
            if(j-i+1<k)j++;
            else if(j-i+1==k){
                v.push_back(q.front());
                if(a[i]==q.front())q.pop_front();
                i++;
                j++;
            }
        }
        return v;
    }
};