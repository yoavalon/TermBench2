#include <iostream>
#include <vector>
#include <set>
#include <queue>

class Graph {
public:
    std::vector<int> nodes;
    std::vector<std::pair<int, int>> edges;

    Graph(std::vector<int> nodes, std::vector<std::pair<int, int>> edges) {
        this->nodes = nodes;
        this->edges = edges;
    }

    std::vector<int> get_neighbors(int node) {
        std::vector<int> neighbors;
        for (const auto& edge : edges) {
            if (edge.first == node) {
                neighbors.push_back(edge.second);
            } else if (edge.second == node) {
                neighbors.push_back(edge.first);
            }
        }
        return neighbors;
    }
};

class Queue {
public:
    std::vector<std::pair<int, std::vector<int>>> items;

    bool is_empty() {
        return items.empty();
    }

    void enqueue(std::pair<int, std::vector<int>> item) {
        items.push_back(item);
    }

    std::pair<int, std::vector<int>> dequeue() {
        std::pair<int, std::vector<int>> item = items.front();
        items.erase(items.begin());
        return item;
    }
};

std::vector<int> bfs(Graph graph, int start, int goal) {
    Queue queue;
    queue.enqueue(std::make_pair(start, std::vector<int>{start}));
    std::set<int> visited;
    while (!queue.is_empty()) {
        auto [node, path] = queue.dequeue();
        if (node == goal) {
            return path;
        }
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            for (int neighbor : graph.get_neighbors(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.enqueue(std::make_pair(neighbor, path));
                    path.push_back(neighbor);
                }
            }
        }
    }
    return {};
}

int main() {
    std::vector<int> nodes = {1, 2, 3, 4, 5};
    std::vector<std::pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    Graph graph(nodes, edges);
    int start_node = 1;
    int goal_node = 5;
    std::vector<int> result = bfs(graph, start_node, goal_node);
    if (!result.empty()) {
        for (int node : result) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
    }
    return 0;
}