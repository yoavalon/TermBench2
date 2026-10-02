#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>

using namespace std;

void dfs(unordered_map<char, vector<char>>& graph, char node, unordered_set<char>& visited, vector<char>& path, vector<vector<char>>& paths) {
    visited.insert(node);
    path.push_back(node);
    if (graph[node].size() == 0) {
        paths.push_back(path);
    }
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited, path, paths);
        }
    }
    path.pop_back();
    visited.erase(node);
}

vector<char> shortest_path(unordered_map<char, vector<char>>& graph, char start, char end) {
    vector<vector<char>> paths;
    dfs(graph, start, unordered_set<char>(), vector<char>(), paths);
    int min_length = numeric_limits<int>::max();
    vector<char> best_path;
    for (const vector<char>& path : paths) {
        if (path.back() == end && path.size() < min_length) {
            min_length = path.size();
            best_path = path;
        }
    }
    return best_path;
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D'}},
        {'C', {'D'}},
        {'D', {}}
    };
    char start_node = 'A';
    char end_node = 'D';
    vector<char> result = shortest_path(graph, start_node, end_node);
    for (char node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}