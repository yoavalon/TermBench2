#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int bfs(const unordered_map<char, vector<char>>& graph, char start, char end) {
    queue<char> q;
    q.push(start);
    unordered_set<char> visited;
    unordered_map<char, int> distances;
    distances[start] = 0;

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        if (node == end) {
            return distances[node];
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (char neighbor : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    distances[neighbor] = distances[node] + 1;
                    q.push(neighbor);
                }
            }
        }
    }
    return -1;
}

int shortest_path(const unordered_map<char, vector<char>>& graph, char start, char end) {
    return bfs(graph, start, end);
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
    cout << shortest_path(graph, 'A', 'F') << endl;
    return 0;
}