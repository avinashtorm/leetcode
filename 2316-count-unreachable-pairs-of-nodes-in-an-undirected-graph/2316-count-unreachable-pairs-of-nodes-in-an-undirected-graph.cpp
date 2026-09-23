class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(i == parent[i])
            return i;

        return parent[i] = find(parent[i], parent);
    }

    void Union(int i, int j, vector<int>& parent, vector<int>& rank) {
        int x = find(i, parent);
        int y = find(j, parent);

        if(x == y)
            return;

        if(rank[x] > rank[y])
            parent[y] = x;
        else if(rank[x] < rank[y])
            parent[x] = y;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& e) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(auto edge : e)
            Union(edge[0], edge[1], parent, rank);

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++)
            mp[find(i, parent)]++;

        long long ans = 0;
        long long previous = 0;

        for(auto x : mp) {
            ans += 1LL * x.second * previous;
            previous += x.second;
        }

        return ans;
    }
};