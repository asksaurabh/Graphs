// Bellman ford expects edges as inputs. Detects -ve wt cycles also
// Relax edges V - 1 times.
// Works only on directed graph(converst undirected if you have to)
class Solution {
public:

    // T.C -> O(V * E)
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        // relax V - 1 times.
        for (int i = 0; i < V - 1; i++) {

            for (vector<int> &edge : edges) {
                int src = edge[0], dest = edge[1], wt = edge[2];

                if (dist[src] != 1e8 && dist[src] + wt < dist[dest]) {
                    dist[dest] = dist[src] + wt;
                }
            }
        }

        // try relaxing for Nth time to detect if there is a negative wt cycle
        for (vector<int> &edge : edges) {
            int src = edge[0], dest = edge[1], wt = edge[2];

            if (dist[src] != 1e8 && dist[src] + wt < dist[dest]) {
                // Negative wt cycle found
                vector<int> res = { -1};
                return res;
            }
        }

        return dist;
    }
};