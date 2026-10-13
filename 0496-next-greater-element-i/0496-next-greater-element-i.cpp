class Solution {
public:
    vector<int> nextGreaterElement(vector<int>&a1, vector<int>&a) {
        int n=a.size();
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=a[i])st.pop();
            if(st.empty())mp[a[i]]=-1;
            else mp[a[i]]=st.top();
            st.push(a[i]);
        }
        vector<int>ans;
        for(int i=0;i<a1.size();i++){
            ans.push_back(mp[a1[i]]);
        }
        return ans;
    }
};