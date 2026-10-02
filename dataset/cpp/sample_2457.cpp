#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

int f(const std::map<std::string, std::vector<std::string>>& g, const std::string& s, const std::string& e) {
    std::vector<std::pair<std::string, int>> q = { {s, 0} };
    std::set<std::string> v;
    while (!q.empty()) {
        auto [n, d] = q.front();
        q.erase(q.begin());
        if (n == e) {
            return d;
        }
        v.insert(n);
        for (const auto& x : g.at(n)) {
            if (v.find(x) == v.end()) {
                q.push_back({x, d + 1});
            }
        }
    }
    return -1;
}

int main() {
    std::map<std::string, std::vector<std::string>> g = {
        {"A", {"B", "C"}},
        {"B", {"D"}},
        {"C", {"D"}},
        {"D", {"E"}},
        {"E", {}}
    };
    std::string s = "A";
    std::string e = "E";
    std::cout << f(g, s, e) << std::endl;
    return 0;
}