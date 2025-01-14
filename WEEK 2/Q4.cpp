#include <iostream>
#include <queue>
using namespace std;

class Graph {
public:
    int V;
    int **adj;

    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V]();
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;  // Assuming an undirected graph
    }

    void bfs(int start) {
        bool *visited = new bool[V]();
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;

        delete[] visited;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from vertex 0:" << endl;
    g.bfs(0);

    return 0;
}

