class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty()&&st.top()>s[i]&&k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k--)st.pop();
        if(st.empty())return "0";
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        cout<<s<<endl;
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        while(s.size()>1&&s[0]=='0')s.erase(0,1);
        cout<<s<<endl;
        return s;
    }
};