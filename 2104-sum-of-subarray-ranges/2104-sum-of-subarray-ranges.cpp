class Solution {
public:
    long long subArrayRanges(vector<int>& a){
        int n=a.size();
        vector<int>l(n),r(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(st.empty())r[i]=n-1-i;
            else r[i]=st.top()-1-i;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty()&&a[st.top()]>a[i])st.pop();
            if(st.empty())l[i]=i;
            else l[i]=i-st.top()-1;
            st.push(i);
        }
        long long mini=0;
        for(int i=0;i<n;i++){
            long long c=1LL*(l[i]+1)*(r[i]+1);
            mini+=1LL*a[i]*c;
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[st.top()]<=a[i])st.pop();
            if(st.empty())r[i]=n-1-i;
            else r[i]=st.top()-1-i;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty()&&a[st.top()]<a[i])st.pop();
            if(st.empty())l[i]=i;
            else l[i]=i-st.top()-1;
            st.push(i);
        }
        long long maxi=0;
        for(int i=0;i<n;i++){
            long long c=1LL*(l[i]+1)*(r[i]+1);
            maxi+=1LL*a[i]*c;
        }
        return maxi-mini;
    }
};
