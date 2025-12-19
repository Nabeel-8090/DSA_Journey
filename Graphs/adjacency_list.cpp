#include <iostream>
#include <vector>

using namespace std;

int main() {

    int V = 5;

    vector<vector<int>> adj(V);

    adj[0].push_back(1);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(2);

    adj[4].push_back(2);

    for(int i=0; i<V; i++) {
        cout << i << " : ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}