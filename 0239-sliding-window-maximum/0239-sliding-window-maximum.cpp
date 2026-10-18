class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        deque<int>d;
        vector<int>v;
        for(int i=0;i<n;i++){
            while(!d.empty()&&d.front()<=i-k)d.pop_front();
            while(!d.empty()&&a[d.back()]<=a[i])d.pop_back();
            d.push_back(i);
            if(i>=k-1)v.push_back(a[d.front()]);
        }
        return v;
    }
};