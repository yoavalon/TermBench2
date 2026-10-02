#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>

std::vector<std::string> find_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end, std::vector<std::string> path = {}) {
    if (path.empty()) {
        path = {start};
    } else {
        path.push_back(start);
    }
    if (start == end) {
        return path;
    }
    if (graph.find(start) == graph.end()) {
        return {};
    }
    for (const auto& node : graph.at(start)) {
        if (std::find(path.begin(), path.end(), node) == path.end()) {
            std::vector<std::string> newpath = find_path(graph, node, end, path);
            if (!newpath.empty()) {
                return newpath;
            }
        }
    }
    return {};
}

int shortest_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::vector<std::string> path = find_path(graph, start, end);
    return !path.empty() ? path.size() - 1 : std::numeric_limits<int>::max();
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> g = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    std::cout << shortest_path(g, "A", "F") << std::endl;
    return 0;
}