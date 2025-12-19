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
};

int main() {

    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Breadth First Search Traversal: "; g.BFS(0);

    return 0;
}