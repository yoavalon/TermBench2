#include <iostream>
#include <map>
#include <set>
#include <limits>

double dijkstra(const std::map<std::string, std::map<std::string, double>>& graph, const std::string& start, const std::string& end) {
    std::map<std::string, double> distances;
    for (const auto& node : graph) {
        distances[node.first] = std::numeric_limits<double>::infinity();
    }
    distances[start] = 0.0;
    std::set<std::string> unvisited(graph.begin(), graph.end());
    std::string current = start;
    while (current != end && !unvisited.empty()) {
        for (const auto& neighbor : graph.at(current)) {
            double distance = distances[current] + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
            }
        }
        unvisited.erase(current);
        if (unvisited.empty()) {
            break;
        }
        current = *std::min_element(unvisited.begin(), unvisited.end(), [&distances](const std::string& a, const std::string& b) {
            return distances[a] < distances[b];
        });
        if (unvisited.find(current) == unvisited.end()) {
            break;
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
    std::cout << dijkstra(graph, start, end) << std::endl;
    return 0;
}