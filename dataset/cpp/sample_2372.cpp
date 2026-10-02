#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

double distance(std::pair<double, double> node1, std::pair<double, double> node2) {
    double x1 = node1.first, y1 = node1.second;
    double x2 = node2.first, y2 = node2.second;
    return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

std::pair<double, double> nearest_node(const std::vector<std::pair<double, double>>& nodes, std::pair<double, double> current) {
    double min_dist = std::numeric_limits<double>::infinity();
    std::pair<double, double> nearest;
    for (const auto& node : nodes) {
        double dist = distance(current, node);
        if (dist < min_dist) {
            min_dist = dist;
            nearest = node;
        }
    }
    return nearest;
}

class Graph {
public:
    std::vector<std::pair<double, double>> nodes;

    Graph(const std::vector<std::pair<double, double>>& nodes) : nodes(nodes) {}

    std::vector<std::pair<double, double>> find_shortest_path(std::pair<double, double> start, std::pair<double, double> end) {
        std::vector<std::pair<double, double>> path;
        std::pair<double, double> current = start;
        while (current != end) {
            path.push_back(current);
            std::pair<double, double> next_node = nearest_node(nodes, current);
            current = next_node;
        }
        path.push_back(end);
        return path;
    }
};

void main() {
    std::vector<std::pair<double, double>> nodes = {{0, 0}, {1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Graph graph(nodes);
    std::pair<double, double> start = nodes[0];
    std::pair<double, double> end = nodes[nodes.size() - 1];
    while (true) {
        std::vector<std::pair<double, double>> path = graph.find_shortest_path(start, end);
        std::cout << "Path found: ";
        for (const auto& node : path) {
            std::cout << "(" << node.first << ", " << node.second << ") ";
        }
        std::cout << std::endl;
    }
}