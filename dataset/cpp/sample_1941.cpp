#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <queue>

double find_shortest_path(std::map<std::string, std::map<std::string, double>> graph, std::string start, std::string end) {
    std::map<std::string, double> distances;
    for (const auto& node : graph) {
        distances[node.first] = std::numeric_limits<double>::infinity();
    }
    distances[start] = 0.0;
    std::vector<std::string> queue = {start};

    while (!queue.empty()) {
        std::string current = queue.front();
        queue.erase(queue.begin());
        for (const auto& neighbor : graph[current]) {
            double distance = distances[current] + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                queue.push_back(neighbor.first);
            }
        }
    }
    return distances[end];
}

int main() {
    std::map<std::string, std::map<std::string, double>> graph = {
        {"A", {{"B", 1.0}, {"C", 4.0}}},
        {"B", {{"A", 1.0}, {"C", 2.0}, {"D", 5.0}}},
        {"C", {{"A", 4.0}, {"B", 2.0}, {"D", 1.0}}},
        {"D", {{"B", 5.0}, {"C", 1.0}}}
    };
    std::string start = "A";
    std::string end = "D";
    double result = find_shortest_path(graph, start, end);
    std::cout << result << std::endl;
    return 0;
}