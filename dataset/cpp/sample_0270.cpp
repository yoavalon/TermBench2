#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

class Graph {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> edges;

    void add_edge(int u, int v, int w) {
        if (edges.find(u) != edges.end()) {
            edges[u].push_back({v, w});
        } else {
            edges[u] = {{v, w}};
        }
    }

    std::vector<std::pair<int, int>> get_neighbors(int u) {
        if (edges.find(u) != edges.end()) {
            return edges[u];
        } else {
            return {};
        }
    }
};

class Dijkstra {
public:
    Graph graph;

    Dijkstra(Graph graph) : graph(graph) {}

    std::vector<int> find_shortest_path(int start, int end) {
        std::priority_queue<std::tuple<int, int, std::vector<int>>, std::vector<std::tuple<int, int, std::vector<int>>>, std::greater<>> q;
        q.push({0, start, {start}});
        std::unordered_map<int, int> dist;
        dist[start] = 0;
        std::set<int> visited;

        while (!q.empty()) {
            auto [cost, node, path] = q.top();
            q.pop();
            if (visited.find(node) != visited.end()) {
                continue;
            }
            visited.insert(node);
            path.push_back(node);
            if (node == end) {
                return path;
            }
            for (auto [neighbor, weight] : graph.get_neighbors(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    int new_cost = cost + weight;
                    q.push({new_cost, neighbor, path});
                }
            }
        }
        return {};
    }
};

void main() {
    Graph graph;
    graph.add_edge(1, 2, 7);
    graph.add_edge(1, 3, 9);
    graph.add_edge(2, 3, 10);
    graph.add_edge(2, 4, 15);
    graph.add_edge(3, 4, 11);
    graph.add_edge(4, 5, 6);
    Dijkstra dijkstra(graph);
    std::vector<int> result = dijkstra.find_shortest_path(1, 5);
    for (int node : result) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
}

int main() {
    main();
    return 0;
}