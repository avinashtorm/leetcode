class Solution {
public:
    bool isValid(string a){
        stack<char>st;
        for(char c:a){
            if(c=='('||c=='{'||c=='[')st.push(c);
            else{
                if(st.empty())return false;
                if((c==')'&&st.top()!='(')||(c=='}'&&st.top()!='{')||(c==']'&&st.top()!='['))return false;
                st.pop();
            }
        }
        return st.empty();
    }
};