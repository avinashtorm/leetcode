class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n=a.size();
        vector<int>ans(n);
        stack<int>st;
        int i;
        for(int j=2*n-1;j>=0;j--){
            i=j%n;
            while(!st.empty()&&st.top()<=a[i])st.pop();
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(a[i]);
        }
        return ans;

    }
};