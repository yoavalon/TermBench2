#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::string> optimize_route(const std::unordered_map<std::string, std::unordered_map<std::string, int>>& routes, 
                                       const std::string& start, 
                                       const std::string& end, 
                                       std::unordered_set<std::string>& visited, 
                                       std::vector<std::string> path) {
    visited.insert(start);
    path.push_back(start);
    if (start == end) {
        return path;
    }
    for (const auto& [neighbor, distance] : routes.at(start)) {
        if (visited.find(neighbor) == visited.end()) {
            std::vector<std::string> result = optimize_route(routes, neighbor, end, visited, path);
            if (!result.empty()) {
                return result;
            }
        }
    }
    return {};
}

int main() {
    std::unordered_map<std::string, std::unordered_map<std::string, int>> routes = {
        {"A", {{"B", 10}, {"C", 15}}},
        {"B", {{"C", 35}, {"D", 25}}},
        {"C", {{"D", 30}}},
        {"D", {}}
    };
    std::string start = "A";
    std::string end = "D";
    std::unordered_set<std::string> visited;
    std::vector<std::string> optimal_path = optimize_route(routes, start, end, visited, {});
    for (const auto& node : optimal_path) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}