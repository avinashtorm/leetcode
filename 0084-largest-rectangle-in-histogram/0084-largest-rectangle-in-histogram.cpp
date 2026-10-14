class Solution {
public:
    int largestRectangleArea(vector<int>&a){
        int n=a.size();
        vector<int>nsl(n); //not exact nsl , index of next element to the (nsl)nearest smaller to left
        vector<int>nsr(n); //not exact nsl , index of previous element to the (nsr)nearest smaller to right
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(st.empty())nsl[i]=0;
            else nsl[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(st.empty())nsr[i]=n-1;
            else nsr[i]=st.top()-1;
            st.push(i);
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++)mx=max(mx,a[i]*(abs(nsl[i]-nsr[i])+1));
        return mx;
    }
};