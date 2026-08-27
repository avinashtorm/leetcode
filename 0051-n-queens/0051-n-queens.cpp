class Solution {
public:
    bool isValid(vector<string>&vs,int r,int c,int n){
        for(int i=0;i<r;i++){
            if(vs[i][c]=='Q')return false;
        }
        int i=r-1,j=c-1;
        while(i>=0&&j>=0){
            if(vs[i][j]=='Q')return false;
            i--;j--;
        }
        i=r-1;j=c+1;
        while(i>=0&&j<n){
            if(vs[i][j]=='Q')return false;
            i--;j++;
        }
        return true;
    }
    void f(vector<vector<string>>&v,vector<string>&vs,int r,int n){
        if(r==n){
            v.push_back(vs);
            return;
        }
        for(int i=0;i<n;i++){
            vs[r][i]='Q';
            if(isValid(vs,r,i,n))f(v,vs,r+1,n);
            vs[r][i]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>>v;
        vector<string>vs;
        string s="";
        for(int i=0;i<n;i++)s.push_back('.');
        for(int i=0;i<n;i++)vs.push_back(s);
        f(v,vs,0,n);
        return v;
    }
};