#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity

// Structure to represent a node in the graph
struct Node {
    int id, dist;
    bool operator<(const Node& other) const { // Required for priority queue
        return dist > other.dist;
    }
};

// Function to perform Dijkstra's algorithm on a graph
vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF); // Distance array
    vector<bool> visited(n, false); // Visited array
    priority_queue<Node> pq; // Priority queue for getting the node with minimum distance

    // Set the distance of the start node to 0 and add it to the priority queue
    dist[start] = 0;
    pq.push({start, 0});

    // Process the nodes in the priority queue
    while (!pq.empty()) {
        // Get the node with minimum distance from the priority queue
        int u = pq.top().id;
        pq.pop();

        // If the node has already been visited, skip it
        if (visited[u]) continue;
        visited[u] = true;

        // Relax the edges of the node and update the distance array and priority queue
        for (auto& edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    return dist;
}

// Driver code
int main() {
    int n, m, start;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Construct the graph as an adjacency list
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cout << "Enter the start, end, and weight of edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graphs
    }

    cout << "Enter the start node: ";
    cin >> start;

    // Find the shortest paths from the start node to all other nodes
    vector<int> dist = dijkstra(graph, start);

    // Print the shortest paths
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "Node " << i << " is not reachable from node " << start << endl;
        else
            cout << "Shortest path from node " << start << " to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}
