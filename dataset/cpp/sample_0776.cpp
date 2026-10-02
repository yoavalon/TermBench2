#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> find_shortest_path(map<string, vector<string>>& graph, const string& start, const string& end, vector<string> path = {}) {
    path.push_back(start);
    if (start == end) {
        return path;
    }
    if (graph.find(start) == graph.end()) {
        return {};
    }
    vector<string> shortest;
    for (const string& node : graph[start]) {
        if (find(path.begin(), path.end(), node) == path.end()) {
            vector<string> newpath = find_shortest_path(graph, node, end, path);
            if (!newpath.empty()) {
                if (shortest.empty() || newpath.size() < shortest.size()) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

int main() {
    map<string, vector<string>> graph = {
        {"A", {"B", "C"}}, {"B", {"C", "D"}}, {"C", {"D"}}, {"D", {"C"}}, {"E", {"F"}}, {"F", {"C"}}
    };
    string start = "A";
    string end = "D";
    vector<string> path = find_shortest_path(graph, start, end);
    for (const string& node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}