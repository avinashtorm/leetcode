class Solution {
public:
    int findCircleNum(vector<vector<int>>&b) {
       int n=b.size(),count=0;
       vector<int>v(n,0);
       vector<vector<int>>a(n);
       queue<int>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]==1&&i!=j){
                a[i].push_back(j);
            }
        }
       }
       for(int i=0;i<n;i++){
        if(v[i]==1)continue;
        count++;
        v[i]=1;
        q.push(i);
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(int j=0;j<a[k].size();j++){
                if(v[a[k][j]]==1)continue;
                v[a[k][j]]=1;
                q.push(a[k][j]);
            }
        }
       }
       return count;
    }
};