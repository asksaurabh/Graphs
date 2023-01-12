class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // If I intend to apply topo sort on directed graph which is not cyclic
        // I will not receive a topological sorting of the graph as there indeg will never reduce
        // to zero.
        int topoSortCount = 0;
        queue<int> q;
        vector<int> indegree(V, 0);

        for (int node = 0; node < V; node++) {
            for (int neighbour : adj[node]) {
                indegree[neighbour]++;
            }
        }

        for (int node = 0; node < V; node++) {
            if (indegree[node] == 0)
                q.push(node);
        }

        while (q.empty() == false) {
            int node = q.front();
            q.pop();

            topoSortCount++;

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return topoSortCount != V ? true : false;
    }
};