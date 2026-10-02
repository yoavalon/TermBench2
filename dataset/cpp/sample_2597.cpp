#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

vector<string> find_shortest_path(map<string, vector<string>> graph, string start, string end) {
    queue<pair<string, vector<string>>> queue;
    vector<string> initial_path = {start};
    queue.push({start, initial_path});
    unordered_set<string> visited;

    while (!queue.empty()) {
        auto [node, path] = queue.front();
        queue.pop();

        if (node == end) {
            return path;
        }

        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (const string& neighbor : graph[node]) {
                vector<string> new_path = path;
                new_path.push_back(neighbor);
                queue.push({neighbor, new_path});
            }
        }
    }
    return {};
}

void main() {
    map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"A", "D", "E"}},
        {"C", {"A", "F"}},
        {"D", {"B"}},
        {"E", {"B", "F"}},
        {"F", {"C", "E"}}
    };
    vector<string> path = find_shortest_path(graph, "A", "F");
    for (const string& node : path) {
        cout << node << " ";
    }
}