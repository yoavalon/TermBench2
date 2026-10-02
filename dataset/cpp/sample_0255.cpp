#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Graph {
public:
    int V;
    std::vector<std::vector<std::pair<int, int>>> graph;

    Graph(int vertices) : V(vertices), graph(vertices) {}

    void add_edge(int u, int v, int weight) {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
};

std::vector<int> dijkstra(Graph& graph, int src) {
    std::vector<int> dist(graph.V, INT_MAX);
    dist[src] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (u_dist > dist[u]) {
            continue;
        }
        for (const auto& edge : graph.graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            int alt = u_dist + weight;
            if (alt < dist[v]) {
                dist[v] = alt;
                pq.push({alt, v});
            }
        }
    }
    return dist;
}

int find_shortest_path(Graph& graph, int start, int end) {
    std::vector<int> distances = dijkstra(graph, start);
    return distances[end];
}

int main() {
    int vertices = 5;
    Graph graph(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 7, 8);
    graph.add_edge(1, 2, 8);
    graph.add_edge(1, 7, 11);
    graph.add_edge(2, 3, 7);
    graph.add_edge(2, 5, 4);
    graph.add_edge(2, 8, 2);
    graph.add_edge(3, 4, 9);
    graph.add_edge(3, 5, 14);
    graph.add_edge(4, 5, 10);
    graph.add_edge(5, 6, 2);
    graph.add_edge(6, 7, 1);
    graph.add_edge(6, 8, 6);
    graph.add_edge(7, 8, 7);
    int start_node = 0;
    int end_node = 4;
    int shortest_path = find_shortest_path(graph, start_node, end_node);
    std::cout << "Shortest path from " << start_node << " to " << end_node << ": " << shortest_path << std::endl;
    return 0;
}