#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000000;

void bfsShortestPath(vector<vector<int>>& adjList, int startNode, vector<int>& distance) {
    queue<int> q;

    distance[startNode] = 0; // Distance from start node to itself is 0
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int neighbor : adjList[currentNode]) {
            if (distance[neighbor] == INF) { // If neighbor hasn't been visited
                distance[neighbor] = distance[currentNode] + 1; // Update distance
                q.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

void printAdjacencyList(const vector<vector<int>>& adjList) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); ++i) {
        cout << "Vertex " << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices = 5;

    vector<vector<int>> adjList(vertices);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);

    printAdjacencyList(adjList);

    vector<int> distance(vertices, INF); 

    cout << "Shortest Path from vertex 0 to all other vertices:" << endl;
    bfsShortestPath(adjList, 0, distance);

    for (int i = 0; i < vertices; ++i) {
        cout << "Vertex " << i << ": Distance = ";
        if (distance[i] == INF) cout << "Infinity"; // Print "Infinity" if distance is still infinity
        else cout << distance[i]; // Otherwise, print the distance
        cout << endl;
    }

    return 0;
}

/*
Adjacency List:

Vertex 0 -> 1 2 
Vertex 1 -> 0 2 3 
Vertex 2 -> 0 1 4 
Vertex 3 -> 1 4 
Vertex 4 -> 2 3 

Shortest Path from vertex 0 to all other vertices:

Vertex 0: Distance = 0
Vertex 1: Distance = 1
Vertex 2: Distance = 1
Vertex 3: Distance = 2
Vertex 4: Distance = 2
*/