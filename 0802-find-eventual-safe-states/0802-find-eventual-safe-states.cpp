class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&graph) {
        int n=graph.size();
        vector<vector<int>>a(n);
        queue<int>q;
	    vector<int>in(n, 0);
	    for(int i=0;i<n;i++) {
	        for(int &j:graph[i]) {
                a[j].push_back(i);
	            in[i]++;
	        }
	    }
	    for(int i=0;i<n;i++)if(in[i]==0)q.push(i);
        vector<int>v;
	    while(!q.empty()) {
	        int x=q.front();
	        q.pop();
            v.push_back(x);
	        for(int &y:a[x]) {
	            in[y]--;
	            if(in[y] == 0)q.push(y);
	        }
	    }
	    sort(v.begin(),v.end());
        return v;
    }
};
