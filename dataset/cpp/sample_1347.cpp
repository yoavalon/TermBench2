#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

vector<string> bfs(unordered_map<string, vector<string>>& graph, string start, string end) {
    queue<pair<string, vector<string>>> q;
    q.push({start, {start}});
    unordered_set<string> visited;
    while (!q.empty()) {
        auto [node, path] = q.front();
        q.pop();
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const auto& neighbor : graph[node]) {
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push({neighbor, newPath});
            }
        }
    }
    return {};
}

vector<string> shortest_path(unordered_map<string, vector<string>>& graph, string start, string end) {
    return bfs(graph, start, end);
}

int main() {
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    string start = "A";
    string end = "F";
    vector<string> path = shortest_path(graph, start, end);
    if (!path.empty()) {
        cout << "Shortest path: ";
        for (const auto& node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found" << endl;
    }
    return 0;
}