class Solution {
    void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &topo) {
        vis[node] = 1;

        for (auto pr : adj[node]) {
            int neighbour = pr.first;
            if (vis[neighbour] == 0)
                dfs(neighbour, adj, vis, topo);
        }

        topo.push(node);
    }
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        stack<int> topo;
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        // 1. Find the topo sort
        vector<int> vis(N, 0);
        for (int node = 0; node < N; node++) {
            if (vis[node] == 0)
                dfs(node, adj, vis, topo);
        }

        // 2. start relaxing the edges.
        int source = 0;
        vector<int> dist(N, INT_MAX);
        dist[source] = 0;

        while (topo.empty() == false) {
            int node = topo.top();
            topo.pop();

            if (dist[node] != INT_MAX) {
                for (auto pr : adj[node]) {
                    int neighbour = pr.first, wt = pr.second;
                    if (dist[neighbour] > dist[node] + wt) {
                        dist[neighbour] = dist[node] + wt;
                    }
                }
            }
        }

        // 3. Return the answer(Update the non-reachables from source)
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }

        return dist;
    }
};