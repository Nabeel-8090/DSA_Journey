#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS Traversal
    void BFS(int srcNode) { // O(V+E)
        queue<int> Q;
        vector<bool> visited(V, false);

        Q.push(srcNode);
        visited[srcNode] = true;

        while(Q.size() > 0) {
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for(int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl;
    }

    // DFS Traversal
    void dfsHelpler(int u, vector<bool>& visited) {  // O(V+E)
        cout << u << " ";
        visited[u] = true;
        for(int v : adj[u]) {
            if(!visited[v]) {
                dfsHelpler(v, visited);
            }
        }
    }

    void DFS() {
        int srcNode = 0;
        vector<bool> visited(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfsHelpler(i, visited);
            }
        }
        cout << endl;
    }
};

int main() {

    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(4, 3);

    cout << "Breadth First Search Traversal: "; g.BFS(0);
    cout << "Depth First Search Traversal: "; g.DFS();

    return 0;
}