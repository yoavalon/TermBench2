#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

vector<vector<string>> initialize_graph(const vector<string>& nodes, const vector<pair<string, string>>& edges) {
    vector<vector<string>> graph(nodes.size());
    for (const auto& node : nodes) {
        for (size_t i = 0; i < nodes.size(); ++i) {
            if (nodes[i] == node) {
                graph[i] = {};
                break;
            }
        }
    }
    for (const auto& edge : edges) {
        for (size_t i = 0; i < nodes.size(); ++i) {
            if (nodes[i] == edge.first) {
                for (size_t j = 0; j < nodes.size(); ++j) {
                    if (nodes[j] == edge.second) {
                        graph[i].push_back(edge.second);
                        graph[j].push_back(edge.first);
                        break;
                    }
                }
                break;
            }
        }
    }
    return graph;
}

vector<string> bfs_shortest_path(const vector<vector<string>>& graph, const string& start, const string& end) {
    queue<pair<string, vector<string>>> q;
    q.push({start, {start}});
    unordered_set<string> visited;
    while (!q.empty()) {
        auto [node, path] = q.front();
        q.pop();
        if (node == end) {
            return path;
        }
        visited.insert(node);
        for (const auto& neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                vector<string> new_path = path;
                new_path.push_back(neighbor);
                q.push({neighbor, new_path});
            }
        }
    }
    return {};
}

vector<string> find_boundary_conditions(const vector<vector<string>>& graph, const string& start, const string& end) {
    vector<string> path = bfs_shortest_path(graph, start, end);
    if (path.empty()) {
        return {};
    }
    vector<string> boundary_nodes;
    for (size_t i = 1; i < path.size() - 1; ++i) {
        boundary_nodes.push_back(path[i]);
    }
    return boundary_nodes;
}

int main() {
    vector<string> nodes = {"A", "B", "C", "D", "E", "F"};
    vector<pair<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "E"}, {"E", "F"}, {"F", "A"}};
    vector<vector<string>> graph = initialize_graph(nodes, edges);
    string start = "A";
    string end = "E";
    vector<string> boundary_conditions = find_boundary_conditions(graph, start, end);
    for (const auto& node : boundary_conditions) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}