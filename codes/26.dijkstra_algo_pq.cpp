#define pii pair<int, int>
class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        pq.push({0, S});   // {dist, node}

        while (pq.empty() == 0) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto pr : adj[node]) {
                int neighbour = pr[0];
                int edgeWeight = pr[1];

                if (dis + edgeWeight < dist[neighbour]) {
                    dist[neighbour] = dis + edgeWeight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        return dist;
    }
};

// T.C -> ElogV