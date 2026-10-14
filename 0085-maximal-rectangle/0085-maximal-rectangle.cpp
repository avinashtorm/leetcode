class Solution {
public:
    int maximalRectangle(vector<vector<char>>&b){
        int n=b.size(),m=b[0].size();
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    a[i][j]=b[i][j]-48;
                }
                else{
                    if(b[i][j]=='0')a[i][j]=0;
                    else a[i][j]=a[i-1][j]+b[i][j]-48;
                }
            }
        }
        stack<int>st;
        vector<vector<int>>nsl(n,vector<int>(m));
        vector<vector<int>>nsr(n,vector<int>(m));
        for(int j=0;j<n;j++){
          for(int i=0;i<m;i++){
            while(!st.empty()&&a[j][st.top()]>=a[j][i])st.pop();
            if(st.empty())nsl[j][i]=0;
            else nsl[j][i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        }
        for(int j=0;j<n;j++){
          for(int i=m-1;i>=0;i--){
            while(!st.empty()&&a[j][st.top()]>=a[j][i])st.pop();
            if(st.empty())nsr[j][i]=m-1;
            else nsr[j][i]=st.top()-1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx=max(mx,a[i][j]*(abs(nsl[i][j]-nsr[i][j])+1));
            }
        }
        return mx;
    }
};