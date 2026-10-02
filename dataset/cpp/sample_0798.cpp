#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<char> dfs(unordered_map<char, vector<char>>& graph, char node, unordered_set<char>& visited, vector<char> path) {
    visited.insert(node);
    path.push_back(node);
    if (path.size() == graph.size()) {
        return path;
    }
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            vector<char> result = dfs(graph, neighbor, visited, path);
            if (!result.empty()) {
                return result;
            }
        }
    }
    return {};
}

vector<char> shortest_path(unordered_map<char, vector<char>>& graph, char start) {
    unordered_set<char> visited;
    vector<char> path = dfs(graph, start, visited, {});
    return path.empty() ? vector<char>() : path;
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };
    char start = 'A';
    vector<char> path = shortest_path(graph, start);
    for (char node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}