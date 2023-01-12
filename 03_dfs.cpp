// Points: Careful of the following things
// 1. Directed or undirected, adjList or adjMatrix, graph starting point.
// INPUT: Undirected graph.
// 6 5
// 0 1
// 0 2
// 1 3
// 2 3
// 4 5
// Time Complexity: O(V + 2E), Space Complexity: O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adjList[]) {
	visited[node] = 1;
	cout << node << " ";

	for (int neighbour : adjList[node]) {
		if (visited[neighbour] == 0) {
			dfs(neighbour, visited, adjList);
		}
	}
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	vector<int> adjList[nodes];
	for (int i = 0; i < edges; i++) {
		int src, dest;
		cin >> src >> dest;
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	vector<int> visited(nodes, 0);
	for (int node = 0; node < nodes; node++) {
		if (visited[node] == 0) {
			dfs(node, visited, adjList);
		}
	}

	return 0;
}