#include <iostream>
#include <vector>
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

    bool detectCycleHelper(int u, vector<bool>& vis, int par) {
        vis[u] = true;
        for(int v : adj[u]) {
            if(!vis[v]) {
                if(detectCycleHelper(v, vis, u)) {
                    return true;
                }
            } else {
                if(v != par) {
                    return true;
                }
            }
        }

        return false;
    }

    bool detectCycle() {
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detectCycleHelper(i, vis, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main() {

    int V = 5;

    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << g.detectCycle() << endl;

    return 0;
}