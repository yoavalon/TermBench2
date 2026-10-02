#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<char> find_shortest_path(unordered_map<char, vector<char>>& graph, char start, char end, set<char>& visited) {
    if (visited.find(start) == visited.end()) {
        visited.insert(start);
        if (start == end) {
            return {start};
        }
        for (char neighbor : graph[start]) {
            if (visited.find(neighbor) == visited.end()) {
                vector<char> path = find_shortest_path(graph, neighbor, end, visited);
                if (!path.empty()) {
                    path.insert(path.begin(), start);
                    return path;
                }
            }
        }
    }
    return {};
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {'G'}},
        {'E', {'F', 'H'}},
        {'F', {'G'}},
        {'G', {'H'}},
        {'H', {}}
    };
    char start = 'A';
    char end = 'H';
    while (true) {
        set<char> visited;
        vector<char> path = find_shortest_path(graph, start, end, visited);
        if (!path.empty()) {
            for (char node : path) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
    return 0;
}