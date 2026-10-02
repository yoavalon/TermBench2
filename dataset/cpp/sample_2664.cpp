#include <iostream>
#include <vector>
#include <queue>

class Graph {
public:
    int nodes;
    std::vector<std::vector<int>> edges;

    Graph(int n) : nodes(n), edges(n) {}

    void connect(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int find_shortest_paths(int start, int end) {
        std::queue<std::pair<int, int>> queue;
        queue.push({start, 0});
        std::vector<bool> visited(nodes, false);
        visited[start] = true;
        while (!queue.empty()) {
            auto [current, distance] = queue.front();
            queue.pop();
            if (current == end) {
                return distance;
            }
            for (int neighbor : edges[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push({neighbor, distance + 1});
                }
            }
        }
        return -1;
    }
};

Graph generate_sequence(int n) {
    Graph graph(n);
    for (int i = 0; i < n; ++i) {
        graph.connect(i, (i + 1) % n);
    }
    return graph;
}

void main() {
    int n = 10;
    Graph graph = generate_sequence(n);
    int start = 0;
    int end = 5;
    int result = graph.find_shortest_paths(start, end);
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}