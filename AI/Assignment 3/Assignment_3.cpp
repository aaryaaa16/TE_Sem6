#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9;

class Graph {
private:
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); 
    }

    int dijkstraMST() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INF); 
        vector<int> parent(V, -1); 
        vector<bool> visited(V, false); 
        int minCost = 0;

        pq.push(make_pair(0, 0));
        dist[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!visited[v] && weight < dist[v]) {
                    dist[v] = weight;
                    parent[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            if (parent[i] != -1)
                minCost += dist[i];
        }

        return minCost;
    }
};

int main() {
    int V;
    cout<<"Enter number of vertices: ";
    cin>>V;
    Graph g(V);

    int u;
    int v;
    int w;
    for (int i = 0; i < V; i++) {
        cout<<"Enter starting and ending vertice of edge "<<i + 1<<": ";
        cin>>u>>v;
        cout<<"Enter weight: ";
        cin>>w;

        g.addEdge(u, v, w);
    }
    // (0, 1, 2);
    // (0, 3, 6);
    // (1, 2, 3);
    // (1, 3, 8);
    // (1, 4, 5);
    // (2, 4, 7);
    // (3, 4, 9);

    int minCost = g.dijkstraMST();
    cout << "Minimum Cost Spanning Tree: " << minCost << endl;

    return 0;
}