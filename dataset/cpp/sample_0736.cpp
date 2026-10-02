#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

vector<string> dfs(map<string, vector<string>>& graph, string node, unordered_set<string>& visited, vector<string>& path) {
    if (visited.find(node) == visited.end()) {
        visited.insert(node);
        path.push_back(node);
        for (const string& neighbor : graph[node]) {
            dfs(graph, neighbor, visited, path);
        }
    }
    return path;
}

vector<string> shortest_path(map<string, vector<string>>& graph, string start, string end) {
    unordered_set<string> visited;
    vector<string> path;
    dfs(graph, start, visited, path);
    for (const string& p : path) {
        if (p == end) {
            return path;
        }
    }
    return {};
}

int main() {
    map<string, vector<string>> graph = {{"A", {"B", "C"}}, {"B", {"D", "E"}}, {"C", {"F"}}, {"D", {}}, {"E", {"F"}}, {"F", {}}};
    string start = "A";
    string end = "F";
    vector<string> result = shortest_path(graph, start, end);
    for (const string& r : result) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}