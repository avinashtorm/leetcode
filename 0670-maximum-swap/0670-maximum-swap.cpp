class Solution {
public:
void f(string &s,int st){
    if(st==s.size())return;
    char m='0'-1;
    int ind;
    for(int i=st;i<s.size();i++){
        if(s[i]>=m){
            m=s[i];
            ind=i;
        }
    }
    if(ind==st||s[ind]==s[st]){
        f(s,st+1);
    }else{
        swap(s[ind],s[st]);
        return;
    }
}
    int maximumSwap(int a) {
        string s=to_string(a);
        f(s,0);
        return stoi(s);
    }
};