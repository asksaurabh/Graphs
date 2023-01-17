class Solution
{
public:
#define pipi pair<int, pair<int, int>>
#define pii pair<int, int>
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // build the MST also.
        vector<int> vis(V, 0);
        priority_queue<pipi, vector<pipi>, greater<pipi>> pq;
        vector<pii> mst;
        int sum = 0;

        // {wt, node, par}
        pq.push({0, {0, -1}});

        // E
        while (pq.empty() == false) {

            // logV
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int nodeParent = pq.top().second.second;
            pq.pop();

            if (vis[node] == 1) continue;

            sum += wt;
            mst.push_back({nodeParent, node});
            vis[node] = 1;

            // VlogV
            for (auto &vec : adj[node]) {
                int neighbour = vec[0], edgeWt = vec[1];
                if (vis[neighbour] == 0) {
                    pq.push({edgeWt, {neighbour, node}});
                }
            }
        }

        // T.C -> (E + V)logV

        return sum;
    }
};