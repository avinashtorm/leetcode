class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
    map<int,unordered_set<int>>mp;
    for(int i=0;i<r.size();i++)mp[r[i][0]].insert(r[i][1]);
    int f=(n-mp.size())*2,c=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        c=0;
        bool g1=!(it->second.contains(2)||it->second.contains(3)||it->second.contains(4)||it->second.contains(5));
        bool g3=!(it->second.contains(4)||it->second.contains(5)||it->second.contains(6)||it->second.contains(7));
        bool g2=!(it->second.contains(6)||it->second.contains(7)||it->second.contains(8)||it->second.contains(9));
        if(g1)c++;
        if(g2)c++;
        if(c==0&&g3)c++;
        f+=c;
    }
    return f;
    }
};