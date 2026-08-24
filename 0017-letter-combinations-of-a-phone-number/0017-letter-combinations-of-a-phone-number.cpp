class Solution {
public:
    unordered_map<int,string>mp;

    void fun(){
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
    }

    void f(string &s,vector<string>&v,string s1,int i){
        if(i==s.size()){
            v.push_back(s1);
            return;
        }

        string temp=mp[s[i]-'0'];

        for(int j=0;j<temp.size();j++){
            s1.push_back(temp[j]);
            f(s,v,s1,i+1);
            s1.pop_back();
        }
    }

    vector<string> letterCombinations(string s) {
        fun();
        vector<string>v;

        if(s.size()==0)return v;

        f(s,v,"",0);
        return v;
    }
};