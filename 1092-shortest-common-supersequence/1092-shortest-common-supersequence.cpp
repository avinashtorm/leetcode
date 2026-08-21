class Solution {
public:
    vector<vector<int>>t;
    string s="";

    string shortestCommonSupersequence(string &s1,string &s2){
        int n=s1.size(),m=s2.size();
        t.assign(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }

        while(n>0&&m>0){
            if(s1[n-1]==s2[m-1]){
                s.push_back(s1[n-1]);
                n--;
                m--;
            }
            else if(t[n-1][m]>t[n][m-1]){
                s.push_back(s1[n-1]);
                n--;
            }
            else{
                s.push_back(s2[m-1]);
                m--;
            }
        }

        while(n>0){
            s.push_back(s1[n-1]);
            n--;
        }

        while(m>0){
            s.push_back(s2[m-1]);
            m--;
        }

        reverse(s.begin(),s.end());
        return s;
    }
};