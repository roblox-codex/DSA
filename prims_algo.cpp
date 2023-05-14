#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vii> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vi dist(n, INF);
    vi parent(n, -1);
    vector<bool> visited(n, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto v : adj[u]) {
            if (!visited[v.first] && v.second < dist[v.first]) {
                dist[v.first] = v.second;
                parent[v.first] = u;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }

    int mstWeight = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            mstWeight += dist[i];
            cout << parent[i] << " - " << i << endl;
        }
    }

    cout << "Minimum Spanning Tree Weight: " << mstWeight << endl;

    return 0;
}
