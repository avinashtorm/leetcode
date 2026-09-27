class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        vector<vector<pair<int, int>>>a(n);
        for(vector<int> &vec : flights) {
            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];
            a[u].push_back({v, cost});
        }
        queue<pair<int, int>>q;
        q.push({src, 0});
        distance[src] = 0;
        int stops = 0;        
        while(!q.empty() && stops <= k) {
            int N = q.size();
            while(N--) {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                for(pair<int, int> &P : a[u]) {
                    int v    = P.first;
                    int cost = P.second;
                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        q.push({v, d+cost});
                    }
                }
            }
            stops++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
