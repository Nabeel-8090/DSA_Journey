#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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

    // BFS Traversal (Queue)
    void bfs() { // O(V+E)
        queue<int> Q;
        vector<bool> visited(V, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                Q.push(i);
                visited[i] = true;
            
                while(!Q.empty()) {
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
            }
        }
        cout << endl;
    }

    // DFS Traversal (Recursive)
    void dfsHelper(int u, vector<bool>& visited) { // O(V+E)
        cout << u << " ";
        visited[u] = true;
        for(int v : adj[u]) {
            if(!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfsHelper(i, visited);
            }
        }
        cout << endl;
    }

    // DFS Traversal (Stack)
    void dfsStack() { // O(V+E)
        stack<int> st;
        vector<bool> visited(V, false);

        for(int start=0; start<V; start++) {
            if(!visited[start]) {
                st.push(start);
                
                while(!st.empty()) {
                    int u = st.top();
                    st.pop();

                    if(!visited[u]) {
                        visited[u] = true;
                        cout << u << " ";

                        for(int i=adj[u].size()-1; i>=0; i--) {
                            int neighbor = adj[u][i];
                            if(!visited[neighbor]) {
                                st.push(neighbor);
                            }
                        }
                    }
                }

            }
        }
    }
};

int main() {

    int V = 5;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "BFS: "; g.bfs();
    cout << "DFS (Recursive): "; g.dfs();
    cout << "DFS (Stack): "; g.dfsStack(); 

    return 0;
}