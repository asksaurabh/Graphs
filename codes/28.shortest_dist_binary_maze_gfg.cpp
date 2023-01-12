#define pii pair<int, int>
class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        queue<pii> q;
        vector<int> di = {1, 0, 0, -1}, dj = {0, -1, 1, 0};

        q.push(source);
        dist[source.first][source.second] = 0;

        while (q.empty() == false) {
            int node_i = q.front().first;
            int node_j = q.front().second;
            int distanceCoveredTillNow = dist[node_i][node_j];
            q.pop();

            if (node_i == destination.first && node_j == destination.second)
                return distanceCoveredTillNow;

            // Traverse on Neighbours
            for (int dir = 0; dir < 4; dir++) {
                int next_i = node_i + di[dir];
                int next_j = node_j + dj[dir];

                if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && grid[next_i][next_j] == 1) {

                    // If the cell is never visited
                    if (dist[next_i][next_j] == INT_MAX) {
                        dist[next_i][next_j] = distanceCoveredTillNow + 1;
                        q.push({next_i, next_j});
                    }

                }
            }
        }

        return -1;
    }
};