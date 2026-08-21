class Solution {
public:
    vector<vector<int>> t;
    string s = "";

    string shortestCommonSupersequence(string &s1, string &s2) {

        int n = s1.size();
        int m = s2.size();

        t.assign(n+1, vector<int>(m+1, 0));

        // LCS table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];

                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }

        // Same as f(s1,s2,n,m)
        while(n != 0 || m != 0) {

            if(n == 0) {
                s += s2[m-1];
                m--;
            }

            else if(m == 0) {
                s += s1[n-1];
                n--;
            }

            else if(s1[n-1] == s2[m-1]) {
                s += s1[n-1];
                n--;
                m--;
            }

            else if(t[n-1][m] >= t[n][m-1]) {
                s += s1[n-1];
                n--;
            }

            else {
                s += s2[m-1];
                m--;
            }
        }

        reverse(s.begin(), s.end());

        return s;
    }
};

