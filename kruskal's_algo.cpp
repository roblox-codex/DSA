#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n, m; // number of vertices and edges
int parent[MAXN], size[MAXN];

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<Edge> edges;

// Find the parent of a node in the Union-Find data structure
int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

// Merge two nodes in the Union-Find data structure
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (size[x] < size[y]) {
        swap(x, y);
    }
    parent[y] = x;
    size[x] += size[y];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end());
    int mst_cost = 0;
    vector<Edge> mst;
    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            mst_cost += e.w;
            mst.push_back(e);
            merge(e.u, e.v);
        }
    }
    cout << "Minimum Spanning Tree cost: " << mst_cost << endl;
    cout << "Edges in the MST: " << endl;
    for (Edge e : mst) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
    return 0;
}
