class Solution {
public:
    bool isValid(string a){
        int i=0;
        stack<char>st;
        while(i<a.size()){
            if(a[i]=='('||a[i]=='{'||a[i]=='[')st.push(a[i]);
            else if(a[i]=='}'||a[i]==')'||a[i]==']'){
                if(st.empty())return false;
                if(a[i]==')'&&st.top()!='(')return false;
                else if(a[i]=='}'&&st.top()!='{')return false;
                else if(a[i]==']'&&st.top()!='[')return false;
                st.pop();
            }
            i++;
        }
        if(!st.empty())return false;
        return true;
    }
};