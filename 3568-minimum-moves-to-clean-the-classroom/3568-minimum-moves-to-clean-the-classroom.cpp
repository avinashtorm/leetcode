
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;

        // Give every litter cell a number: 0, 1, 2, ...
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        // All litter already collected
        if (litterCount == 0)
            return 0;

        int fullMask = (1 << litterCount) - 1;

        /*
            State:
            row, col, remaining energy, mask
        */

        struct State {
            int r;
            int c;
            int energy;
            int mask;
            int dist;
        };

        queue<State> q;

        /*
            visited[r][c][energy][mask]

            Since:
            m,n <= 20
            energy <= 50
            litter <= 10
        */

        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            // Have we collected every litter?
            if (cur.mask == fullMask)
                return cur.dist;

            // If no energy, we cannot move.
            if (cur.energy == 0)
                continue;

            for (int d = 0; d < 4; d++) {

                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Moving costs 1 energy
                int newEnergy = cur.energy - 1;

                // Reset area
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                // Collect litter if present
                int newMask = cur.mask;

                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }

                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        cur.dist + 1
                    });
                }
            }
        }

        return -1;
    }
};