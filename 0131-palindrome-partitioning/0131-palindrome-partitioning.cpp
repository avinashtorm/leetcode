class Solution {
public:
bool isP(string &s,int st,int e){
    int i=st,j=e;
    bool f=true;
    while(i<j){
        if(s[i]!=s[j])f=false;
        i++;
        j--;
    }
    return f;
}
void f(vector<vector<string>>&v,vector<string>vs,int st,string &s,int n){
    if(st==n){
        v.push_back(vs);
        return;
    }
    for(int i=st;i<n;i++){
        if(isP(s,st,i)){
            vs.push_back(s.substr(st,i-st+1));
            f(v,vs,i+1,s,n);
            vs.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>v;
        vector<string>vs;
        f(v,vs,0,s,n);
        return v;
    }
};