// Only exists in DAG
// A linear order of vertices such that if there is an edge between u and v, u appears before
// v in that ordering.

class Solution
{
	void dfs(int node, vector<int> &vis, stack<int> &st , vector<int> *adj) {
		vis[node] = 1;

		// Resolve all the neighbouring nodes first which have current node as dependency
		for (int neighbour : adj[node]) {
			if (vis[neighbour] == 0) {
				dfs(neighbour, vis, st, adj);
			}
		}

		st.push(node);
	}
public:

	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> res;
		stack<int> st;
		vector<int> vis(V, 0);

		for (int node = 0; node < V; node++) {
			if (vis[node] == 0) {
				dfs(node, vis, st, adj);
			}
		}

		while (st.empty() == false) {
			res.push_back(st.top());
			st.pop();
		}

		return res;
	}
};