#define vi vector<int>
class Solution {
    bool isCyclic(int node, vi &vis, vi &pathVis, vi &checkSafeNode, vi adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;
        checkSafeNode[node] = 0;

        for (int neighbour : adj[node]) {
            if (vis[neighbour] == 0) {
                bool isCycleFoundInNeighbour = isCyclic(neighbour, vis, pathVis, checkSafeNode, adj);
                if (isCycleFoundInNeighbour == true) {
                    checkSafeNode[node] = 0;
                    return true;
                }
            }

            else if (vis[neighbour] == 1 && pathVis[neighbour] == 1) {
                checkSafeNode[node] = 0;
                return true;
            }
        }

        checkSafeNode[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Anyone who is a part of the cycle can't be a safe node.
        // Anyone who leads to a cycle can't be a safe node.? -> How to do this
        // Look we return as soon as we find a cycle. hence its vis and pathvis remains marked 1
        // If someone is trying to enter into a cycle they will encounter a neighbour with vis and pathVis as 1.

        vector<int> vis(V, 0), pathVis(V, 0), checkSafeNode(V, 0);
        vector<int> safeNodes;
        for (int node = 0; node < V; node++) {
            if (vis[node] == 0) {
                isCyclic(node, vis, pathVis, checkSafeNode, adj);
            }
        }

        for (int node = 0; node < V; node++) {
            if (checkSafeNode[node] == 1)
                safeNodes.push_back(node);
        }

        return safeNodes;
    }
};