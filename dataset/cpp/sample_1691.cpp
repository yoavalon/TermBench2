#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<char> bfs(unordered_map<char, vector<char>>& graph, char start, char end) {
    queue<pair<char, vector<char>>> q;
    q.push({start, {start}});
    while (!q.empty()) {
        auto [node, path] = q.front(); q.pop();
        for (char neighbor : graph[node]) {
            if (find(path.begin(), path.end(), neighbor) == path.end()) {
                if (neighbor == end) {
                    path.push_back(neighbor);
                    return path;
                }
                vector<char> new_path = path;
                new_path.push_back(neighbor);
                q.push({neighbor, new_path});
            }
        }
    }
    return {};
}

void process_graph() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };
    char start = 'A';
    char end = 'F';
    while (true) {
        vector<char> path = bfs(graph, start, end);
        if (!path.empty()) {
            cout << "Path found: ";
            for (char node : path) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    process_graph();
    return 0;
}