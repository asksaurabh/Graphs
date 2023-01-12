class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        st.insert({0, S});   // {dist, node}

        while (st.empty() == false) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for (auto pr : adj[node]) {
                int neighbour = pr[0];
                int edgeWeight = pr[1];

                if (dis + edgeWeight < dist[neighbour]) {
                    // erase if already reached somehow to eliminate re-traversal with big dis.
                    if (dist[neighbour] != 1e9) {
                        st.erase({dist[neighbour], neighbour});
                    }

                    dist[neighbour] = dis + edgeWeight;
                    st.insert({dist[neighbour], neighbour});
                }
            }
        }

        return dist;
    }
};