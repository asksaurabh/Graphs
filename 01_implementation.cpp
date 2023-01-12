// Pointers:
// 1. Check what is the starting value of node. Do the allocation accordingly.
// 2. Check if you want to use adjList or adjMatrix or edgeList.
// 3. Check if the edges have weights or not.
// 4. Check if the graph is directed or undirected.

// Unweighted INPUT: Undirected graph with 3 nodes and 3 edges starting with node = 1
// 3 3
// 1 2
// 1 3
// 2 3

// Weighted Input: Undirected graph with 3 nodes and 3 edges starting with node = 1
// 3 3
// 1 2 10
// 1 3 30
// 2 3 20

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// 1. Adjacency Matrix form with static allocation
// int main() {
// 	int nodes, edges;
// 	cin >> nodes >> edges;

// 	int adjMatrix[nodes + 1][nodes + 1];
// 	memset(adjMatrix, 0, sizeof(adjMatrix));

// 	for (int i = 0; i < edges; i++) {
// 		int src, dest;
// 		cin >> src >> dest;
// 		adjMatrix[src][dest] = 1;
// 		adjMatrix[dest][src] = 1;
// 	}

// 	for (int i = 0; i < nodes + 1; i++) {
// 		for (int j = 0; j < nodes + 1; j++) {
// 			cout << adjMatrix[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }


// 2. Adjacency Matrix form with vector allocation
// int main() {
// 	int nodes, edges;
// 	cin >> nodes >> edges;

// 	vector<vector<int>> adjMatrix(nodes + 1, vector<int> (nodes + 1, 0));

// 	for (int i = 0; i < edges; i++) {
// 		int src, dest;
// 		cin >> src >> dest;
// 		adjMatrix[src][dest] = 1;
// 		adjMatrix[dest][src] = 1;
// 	}

// 	for (int i = 0; i < nodes + 1; i++) {
// 		for (int j = 0; j < nodes + 1; j++) {
// 			cout << adjMatrix[i][j] << " ";
// 		}
// 		cout << endl;
// 	}
// }

// 3. Adjacency List Implementation using array of vectors.
// int main() {
// 	int nodes, edges;
// 	cin >> nodes >> edges;

// 	// array of lists
// 	vector<int> adjList[nodes + 1];

// 	for (int i = 0; i < edges; i++) {
// 		int src, dest;
// 		cin >> src >> dest;
// 		adjList[src].push_back(dest);
// 		adjList[dest].push_back(src);
// 	}

// 	for (auto nodeList : adjList) {
// 		for (auto neighbours : nodeList) {
// 			cout << neighbours << " ";
// 		}
// 		cout << endl;
// 	}
// }


// 4. Adjacency Matrix Implementation with weights on edges.
// adjMatrix[src][dest] = weight;


// 5. Adjacency List Implementation with weights on edges.
int main() {
	int nodes, edges;
	cin >> nodes >> edges;

	// Array of vector of pairs.
	vector<pair<int, int>> adjList[nodes + 1];
	for (int i = 0; i < edges; i++) {
		int src, dest, weight;
		cin >> src >> dest >> weight;

		adjList[src].push_back({dest, weight});
		adjList[dest].push_back({src, weight});
	}

	for (auto nodeList : adjList) {
		for (pair<int, int> neighbour : nodeList) {
			cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
		}
		cout << endl;
	}
}