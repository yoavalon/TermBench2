#include <iostream>
#include <vector>
#include <deque>

class Graph {
public:
    int n;
    std::vector<std::vector<int>> edges;

    Graph(int n) : n(n), edges(n) {}

    void add_edge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    std::vector<int> get_neighbors(int v) {
        return edges[v];
    }
};

int bfs(Graph graph, int start, int end) {
    std::vector<bool> visited(graph.n, false);
    std::deque<std::pair<int, int>> queue;
    queue.push_back({start, 0});
    visited[start] = true;
    while (!queue.empty()) {
        auto [current, distance] = queue.front();
        queue.pop_front();
        if (current == end) {
            return distance;
        }
        for (int neighbor : graph.get_neighbors(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back({neighbor, distance + 1});
            }
        }
    }
    return -1;
}

int find_shortest_path(Graph graph, int start, int end) {
    return bfs(graph, start, end);
}

int main() {
    int n = 10;
    Graph graph(n);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(7, 8);
    graph.add_edge(8, 9);
    graph.add_edge(9, 0);
    int start = 0;
    int end = 5;
    int path_length = find_shortest_path(graph, start, end);
    std::cout << path_length << std::endl;
    return 0;
}