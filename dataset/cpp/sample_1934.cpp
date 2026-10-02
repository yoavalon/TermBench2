#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

map<char, map<char, double>> graph;
map<char, double> dijkstra(char start) {
    map<char, double> distances;
    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<double>::infinity();
    }
    distances[start] = 0.0;
    priority_queue<pair<double, char>, vector<pair<double, char>>, greater<pair<double, char>>> priority_queue;
    priority_queue.push({0.0, start});
    while (!priority_queue.empty()) {
        double current_distance = priority_queue.top().first;
        char current_node = priority_queue.top().second;
        priority_queue.pop();
        if (current_distance > distances[current_node]) {
            continue;
        }
        for (const auto& neighbor : graph[current_node]) {
            double distance = current_distance + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                priority_queue.push({distance, neighbor.first});
            }
        }
    }
    return distances;
}

void main() {
    graph['A'][{'B', 1.0}] = 1.0;
    graph['A'][{'C', 4.0}] = 4.0;
    graph['B'][{'A', 1.0}] = 1.0;
    graph['B'][{'C', 2.0}] = 2.0;
    graph['B'][{'D', 5.0}] = 5.0;
    graph['C'][{'A', 4.0}] = 4.0;
    graph['C'][{'B', 2.0}] = 2.0;
    graph['C'][{'D', 1.0}] = 1.0;
    graph['D'][{'B', 5.0}] = 5.0;
    graph['D'][{'C', 1.0}] = 1.0;
    char start_node = 'A';
    map<char, double> result = dijkstra(start_node);
    for (const auto& node : result) {
        cout << node.first << ": " << node.second << endl;
    }
}

int main() {
    main();
    return 0;
}