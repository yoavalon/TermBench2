#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <map>

using namespace std;

vector<char> bfs_shortest_path(map<char, vector<char>> graph, char start, char goal) {
    queue<pair<char, vector<char>>> q;
    q.push(make_pair(start, vector<char>{start}));
    unordered_set<char> visited;
    while (!q.empty()) {
        pair<char, vector<char>> node_path = q.front();
        q.pop();
        char node = node_path.first;
        vector<char> path = node_path.second;
        if (node == goal) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (char neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    vector<char> new_path = path;
                    new_path.push_back(neighbor);
                    q.push(make_pair(neighbor, new_path));
                }
            }
        }
    }
    return vector<char>(); // Return empty vector if no path found
}

int main() {
    map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {'G'}},
        {'E', {'F'}},
        {'F', {'G'}},
        {'G', {}}
    };
    char start_node = 'A';
    char goal_node = 'G';
    vector<char> result = bfs_shortest_path(graph, start_node, goal_node);
    for (char node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}