#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<char> find_shortest_path(unordered_map<char, unordered_set<char>>& graph, char start, char end) {
    queue<pair<char, vector<char>>> q;
    q.push({start, {start}});
    while (!q.empty()) {
        auto [vertex, path] = q.front(); q.pop();
        for (char next_vertex : graph[vertex]) {
            if (find(path.begin(), path.end(), next_vertex) == path.end()) {
                if (next_vertex == end) {
                    path.push_back(next_vertex);
                    return path;
                } else {
                    vector<char> new_path = path;
                    new_path.push_back(next_vertex);
                    q.push({next_vertex, new_path});
                }
            }
        }
    }
    return {};
}

int main() {
    unordered_map<char, unordered_set<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };
    char start = 'A';
    char end = 'F';
    vector<char> result = find_shortest_path(graph, start, end);
    for (char vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;
    return 0;
}