#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <string>

std::vector<std::pair<std::string, double>> graph[4];
std::unordered_set<std::string> visited;

int find_shortest_path(const std::string& start, const std::string& end) {
    std::queue<std::pair<std::string, double>> queue;
    queue.push({start, 0});
    while (!queue.empty()) {
        auto [node, dist] = queue.front();
        queue.pop();
        if (node == end) {
            return dist;
        }
        if (visited.find(node) != visited.end()) {
            continue;
        }
        visited.insert(node);
        for (const auto& [neighbor, weight] : graph[node]) {
            queue.push({neighbor, dist + weight});
        }
    }
    return -1;
}

int main() {
    graph[0] = {{"B", 1.1}, {"C", 4.5}};
    graph[1] = {{"A", 1.1}, {"C", 2.3}, {"D", 5.6}};
    graph[2] = {{"A", 4.5}, {"B", 2.3}, {"D", 1.2}};
    graph[3] = {{"B", 5.6}, {"C", 1.2}};

    std::string start = "A";
    std::string end = "D";
    int result = find_shortest_path(start, end);
    std::cout << result << std::endl;
    return 0;
}