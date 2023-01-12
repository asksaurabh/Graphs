class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Do a bfs from the source
        vector<int> dist(N, 0);
        vector<int> adj[N];
        vector<int> vis(N, 0);

        // 1. Form an adj list
        for (vector<int> edge : edges) {
            int src = edge[0], dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }

        // 2. Do a BFS from the source
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        vis[src] = 1;

        while (q.empty() == false) {
            int node = q.front();
            q.pop();

            for (int neighbour : adj[node]) {
                if (vis[neighbour] == 0) {
                    q.push(neighbour);
                    vis[neighbour] = 1;
                    dist[neighbour] = dist[node] + 1;
                }
            }
        }

        // 3. Return ans in appropriate format
        for (int node = 0; node < N; node++) {
            if (vis[node] == 0) {
                dist[node] = -1;
            }
        }

        return dist;
    }
};