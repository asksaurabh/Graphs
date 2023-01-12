class Solution {
    bool dfs(int node, vector<int> &vis, vector<int> &currPath, vector<int> adj[]) {
        vis[node] = 1;
        currPath[node] = 1;

        for (int neighbour : adj[node]) {
            if (vis[neighbour] == 0) {
                bool isCycleFoundInNeighbour = dfs(neighbour, vis, currPath, adj);
                if (isCycleFoundInNeighbour == true)
                    return true;
            }

            else if (vis[neighbour] == 1 and currPath[neighbour] == 1) {
                return true;
            }
        }

        currPath[node] = 0;
        return false;
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0), currPath(V, 0);
        for (int node = 0; node < V; node++) {
            if (vis[node] == 0) {
                if (dfs(node, vis, currPath, adj) == true) {
                    return true;
                }
            }
        }

        return false;
    }
};