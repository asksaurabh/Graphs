#define pii pair<int, int>
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

        vector<pair<int, int>> adj[n + 1];
        for (vector<int> &edge : edges) {
            int src = edge[0], dest = edge[1], wt = edge[2];
            adj[src].push_back({dest, wt});
            adj[dest].push_back({src, wt});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1, -1);

        int source = 1;
        dist[source] = 0;
        pq.push({0, source});

        while (pq.empty() == false) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto pr : adj[node]) {
                int neighbour = pr.first, edgeWeight = pr.second;

                if (dis + edgeWeight < dist[neighbour]) {
                    dist[neighbour] = dis + edgeWeight;
                    parent[neighbour] = node;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        vector<int> res;
        if (dist[n] == 1e9) {
            res.push_back(-1);
            return res;
        }

        int node = n;
        while (node != -1) {
            res.push_back(node);
            node = parent[node];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};