class Solution {
public:
    bool canFinish(int n, vector<vector<int>>&e) {
        vector<vector<int>>a(n);
        for(auto &x:e)a[x[0]].push_back(x[1]);
        vector<int>in(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i].size();j++){
                in[a[i][j]]++;
            }
        }
        for(int i=0;i<n;i++)if(in[i]==0){
            q.push(i);
        }
        while(!q.empty()){
            int p=q.front();
            q.pop();
            n--;
            for(int i=0;i<a[p].size();i++){
                in[a[p][i]]--;
                if(in[a[p][i]]==0)q.push(a[p][i]);
            }
        }
        return n==0?true:false;
    }
};