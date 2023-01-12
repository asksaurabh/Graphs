// Points: Careful of the following things
// 1. Directed or undirected, adjList or adjMatrix, graph starting point.
// INPUT: Undirected graph.
// 6 5
// 0 1
// 0 2
// 1 3
// 2 3
// 4 5
// Time Complexity: O(V + 2E)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int source, vector<int> &visited, vector<int> adjList[]) {
	queue<int> q;
	q.push(source);
	visited[source] = 1;

	while (q.empty() == false) {
		int currNode = q.front();
		q.pop();

		cout << currNode << " ";
		for (int neighbour : adjList[currNode]) {
			if (visited[neighbour] == false) {
				q.push(neighbour);
				visited[neighbour] = 1;
			}
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
			bfs(node, visited, adjList);
		}
	}

	return 0;
}