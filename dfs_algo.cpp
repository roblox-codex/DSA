#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi& adj, vi& visited, int u) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, visited, v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vvi adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, i);
        }
    }

    return 0;
}
