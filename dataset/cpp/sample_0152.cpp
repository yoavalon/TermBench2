#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <map>

using namespace std;

vector<char> bfs(map<char, vector<char>>& graph, char start, char end) {
    queue<pair<char, vector<char>>> queue;
    queue.push({start, {start}});
    unordered_set<char> visited;
    while (!queue.empty()) {
        pair<char, vector<char>> current = queue.front();
        queue.pop();
        char node = current.first;
        vector<char> path = current.second;
        if (node == end) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (char neighbor : graph[node]) {
                vector<char> newPath = path;
                newPath.push_back(neighbor);
                queue.push({neighbor, newPath});
            }
        }
    }
    return {};
}

vector<char> find_shortest_path(map<char, vector<char>>& graph, char start, char end) {
    return bfs(graph, start, end);
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };
    char start_node = 'A';
    char end_node = 'F';
    vector<char> path = find_shortest_path(graph, start_node, end_node);
    for (char node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}