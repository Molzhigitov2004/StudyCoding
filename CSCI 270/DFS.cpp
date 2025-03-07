#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // Uncomment this line if the graph is undirected
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(start);
        
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            
            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
            }
            
            for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices (0 to 5)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "Depth-First Search starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
