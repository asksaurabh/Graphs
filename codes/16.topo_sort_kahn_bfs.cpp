class Solution
{
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> res;
		vector<int> indegree(V, 0);
		queue<int> q;

		for (int node = 0; node < V; node++) {
			for (int neighbour : adj[node]) {
				indegree[neighbour]++;
			}
		}

		// Start with the ones which have no dependency.
		for (int node = 0; node < V; node++) {
			if (indegree[node] == 0)
				q.push(node);
		}

		while (q.empty() == false) {
			int node = q.front();
			q.pop();

			res.push_back(node);

			// Resolve all its neighbours
			for (int neighbour : adj[node]) {
				--indegree[neighbour];
				if (indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}

		return res;
	}
};