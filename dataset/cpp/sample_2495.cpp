#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <queue>

std::vector<std::pair<std::string, int>> find_shortest_path(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::queue<std::pair<std::string, int>> q;
    std::unordered_set<std::string> v;
    q.push({start, 0});
    while (!q.empty()) {
        auto [n, d] = q.front();
        q.pop();
        if (n == end) {
            return {{"", d}};
        }
        v.insert(n);
        for (const auto& nxt : graph.at(n)) {
            if (v.find(nxt) == v.end()) {
                q.push({nxt, d + 1});
            }
        }
    }
    return {{"", -1}};
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> g = {
        {"A", {"B", "C"}}, {"B", {"D", "E"}}, {"C", {"F"}}, {"D", {"G"}}, {"E", {"F"}}, {"F", {"G"}}, {"G", {}}
    };
    auto result = find_shortest_path(g, "A", "G");
    std::cout << result[0].second << std::endl;
    return 0;
}