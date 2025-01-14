#include <iostream>
#include <stack>
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
    }

    void dfs(int start) {
        bool *visited = new bool[V]();
        stack<int> s;
        int pushIdx = 0, popIdx = 0;
        int *pushOrder = new int[V], *popOrder = new int[V];
        
        s.push(start);
        visited[start] = true;
        pushOrder[pushIdx++] = start;

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            popOrder[popIdx++] = node;

            for (int i = 0; i < V; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                    pushOrder[pushIdx++] = i;
                }
            }
        }

        for (int i = 0; i < pushIdx; i++) cout << pushOrder[i] << " ";
        cout << "\n";
        for (int i = 0; i < popIdx; i++) cout << popOrder[i] << " ";
        cout << "\n";

        delete[] visited;
        delete[] pushOrder;
        delete[] popOrder;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.dfs(0);
    return 0;
}

