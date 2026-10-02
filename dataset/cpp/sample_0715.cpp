#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<char> dfs(unordered_map<char, vector<char>>& graph, char start, char end, vector<char> path, unordered_set<char> visited) {
    path.push_back(start);
    visited.insert(start);
    if (start == end) {
        return path;
    }
    for (char neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            vector<char> result = dfs(graph, neighbor, end, path, visited);
            if (!result.empty()) {
                return result;
            }
        }
    }
    return {};
}

vector<char> shortest_path(unordered_map<char, vector<char>>& graph, char start, char end) {
    vector<char> path = dfs(graph, start, end, {}, {});
    return path.empty() ? vector<char>() : path;
}

int main() {
    unordered_map<char, vector<char>> graph;
    graph['A'].extend({'B', 'C'});
    graph['B'].extend({'C', 'D'});
    graph['C'].extend({'D'});
    graph['D'].push_back('E');
    char start = 'A';
    char end = 'E';
    vector<char> result = shortest_path(graph, start, end);
    for (char node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}