#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited, vector<int>& component) {
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        component.push_back(currentNode);

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
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
        for (int j = 0; j < adjList[i].size(); ++j) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

void printConnectedComponents(const vector<vector<int>>& connectedComponents) {
    cout << "Connected Components in the Graph:" << endl;
    for (int i = 0; i < connectedComponents.size(); ++i) {
        cout << "Component " << i + 1 << ": ";
        for (int j = 0; j < connectedComponents[i].size(); ++j) {
            cout << connectedComponents[i][j] << " ";
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
    //addEdge(adjList, 5, 6); // Additional edge to create a disconnected component

    printAdjacencyList(adjList);

    vector<bool> visited(vertices, false);
    vector<vector<int>> connectedComponents;

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            vector<int> component;
            bfs(adjList, i, visited, component);
            connectedComponents.push_back(component);
        }
    }

    printConnectedComponents(connectedComponents);

    return 0;
}


/*
Adjacency List:

Vertex 0 -> 1 2 
Vertex 1 -> 0 2 3 
Vertex 2 -> 0 1 4 
Vertex 3 -> 1 4 
Vertex 4 -> 2 3 

Connected Components in the Graph:

Component 1: 0 1 2 3 4 
*/

/*
Adjacency List:

Vertex 0 -> 1 2 
Vertex 1 -> 0 2 3 
Vertex 2 -> 0 1 4 
Vertex 3 -> 1 4 
Vertex 4 -> 2 3 
Vertex 5 -> 6 
Vertex 6 -> 5 

Connected Components in the Graph:

Component 1: 0 1 2 3 4 
Component 2: 5 6 
*/