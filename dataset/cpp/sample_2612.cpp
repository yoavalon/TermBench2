#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

std::unordered_map<int, std::vector<std::pair<int, int>>> build_graph(const std::vector<std::tuple<int, int, int>>& edges) {
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
    for (const auto& edge : edges) {
        int u, v, w;
        std::tie(u, v, w) = edge;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    return graph;
}

std::pair<std::unordered_map<int, int>, std::unordered_map<int, int>> dijkstra(const std::unordered_map<int, std::vector<std::pair<int, int>>>& graph, int start, int end) {
    std::unordered_map<int, int> dist;
    for (const auto& node : graph) {
        dist[node.first] = std::numeric_limits<int>::max();
    }
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> queue;
    queue.emplace(0, start);
    std::unordered_map<int, int> path;
    while (!queue.empty()) {
        int current_dist = queue.top().first;
        int current_node = queue.top().second;
        queue.pop();
        if (current_dist > dist[current_node]) {
            continue;
        }
        if (current_node == end) {
            break;
        }
        for (const auto& neighbor : graph.at(current_node)) {
            int distance = current_dist + neighbor.second;
            if (distance < dist[neighbor.first]) {
                dist[neighbor.first] = distance;
                path[neighbor.first] = current_node;
                queue.emplace(distance, neighbor.first);
            }
        }
    }
    return {dist, path};
}

std::vector<int> reconstruct_path(const std::unordered_map<int, int>& path, int start, int end) {
    std::vector<int> total_path = {end};
    while (total_path.back() != start) {
        total_path.push_back(path.at(total_path.back()));
    }
    std::reverse(total_path.begin(), total_path.end());
    return total_path;
}

void main() {
    std::vector<std::tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2},
        {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}
    };
    auto graph = build_graph(edges);
    int start_node = 0;
    int end_node = 4;
    auto [distances, paths] = dijkstra(graph, start_node, end_node);
    std::vector<int> shortest_path = reconstruct_path(paths, start_node, end_node);
    std::cout << "Shortest path: ";
    for (int node : shortest_path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    std::cout << "Distance: " << distances[end_node] << std::endl;
}