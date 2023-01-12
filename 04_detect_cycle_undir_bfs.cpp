#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycleBFS(int source, vector<int> &visited, vector<int> adjList[]) {
	queue<int> q;
	q.push(source);
	visited[source] = 1;

	vector<int> parent(visited.size() + 1, -1);

	while (q.empty() == false) {
		int currNode = q.front();
		q.pop();

		for (int neighbour : adjList[currNode]) {
			if (visited[neighbour] == false) {
				q.push(neighbour);
				visited[neighbour] = 1;
				parent[neighbour] = currNode;
			}

			else if (visited[neighbour] == true and parent[currNode] != neighbour) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int totalNodes, totalEdges;
	cin >> totalNodes >> totalEdges;

	vector<int> adjList[totalNodes + 1];
	for (int i = 0; i < totalEdges; i++) {
		int src, dest;
		cin >> src >> dest;
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	vector<int> visited(totalNodes + 1);
	bool isCyclePresent = false;

	for (int node = 1; node <= totalNodes; node++) {
		if (visited[node] == false) {
			if (isCycleBFS(node, visited, adjList)) {
				cout << "Cycle Present";
				isCyclePresent = true;
				break;
			}
		}
	}

	if (isCyclePresent == false) cout << "Cycle Not Present";
	return 0;
}