#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

class Graph {
public:
    std::unordered_map<std::string, std::vector<std::string>> edges;

    void add_edge(const std::string& node, const std::string& neighbor) {
        if (edges.find(node) == edges.end()) {
            edges[node] = {};
        }
        edges[node].push_back(neighbor);
    }

    std::vector<std::string> get_neighbors(const std::string& node) {
        if (edges.find(node) != edges.end()) {
            return edges[node];
        }
        return {};
    }
};

class Queue {
public:
    std::vector<std::string> items;

    void enqueue(const std::string& item) {
        items.push_back(item);
    }

    std::string dequeue() {
        std::string item = items.front();
        items.erase(items.begin());
        return item;
    }

    bool is_empty() const {
        return items.empty();
    }
};

bool bfs(const Graph& graph, const std::string& start, const std::string& goal) {
    Queue queue;
    std::set<std::string> visited;
    queue.enqueue(start);
    visited.insert(start);
    while (!queue.is_empty()) {
        std::string current = queue.dequeue();
        for (const std::string& neighbor : graph.get_neighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.enqueue(neighbor);
                if (neighbor == goal) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    Graph graph;
    graph.add_edge("A", "B");
    graph.add_edge("B", "C");
    graph.add_edge("C", "D");
    graph.add_edge("D", "E");
    graph.add_edge("E", "F");
    graph.add_edge("F", "G");
    graph.add_edge("G", "H");
    graph.add_edge("H", "I");
    graph.add_edge("I", "J");
    graph.add_edge("J", "K");
    std::string start_node = "A";
    std::string goal_node = "K";
    while (true) {
        if (bfs(graph, start_node, goal_node)) {
            std::cout << "Goal reached." << std::endl;
        } else {
            std::cout << "Goal not found." << std::endl;
        }
    }
    return 0;
}