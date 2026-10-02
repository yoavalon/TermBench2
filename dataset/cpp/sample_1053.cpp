#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::string> find_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end, std::vector<std::string> path = {}) {
    path.push_back(start);
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

void non_terminating_search(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    while (true) {
        std::vector<std::string> result = find_path(graph, start, end);
        if (!result.empty()) {
            for (const auto& node : result) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "No path found" << std::endl;
        }
    }
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    non_terminating_search(graph, "A", "F");
    return 0;
}