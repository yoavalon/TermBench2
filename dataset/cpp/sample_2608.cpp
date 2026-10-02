#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Graph {
public:
    std::vector<int> nodes;
    std::unordered_map<int, std::vector<int>> adj_list;

    Graph(const std::vector<int>& nodes) : nodes(nodes) {
        for (int node : nodes) {
            adj_list[node] = {};
        }
    }

    void add_edge(int node1, int node2) {
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
};

class ShortestPathFinder {
public:
    Graph graph;

    ShortestPathFinder(const Graph& graph) : graph(graph) {}

    int bfs(int start, int end) {
        std::queue<std::pair<int, int>> queue;
        queue.push({start, 0});
        std::unordered_set<int> visited;
        while (!queue.empty()) {
            auto [node, dist] = queue.front();
            queue.pop();
            if (node == end) {
                return dist;
            }
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                for (int neighbor : graph.adj_list[node]) {
                    queue.push({neighbor, dist + 1});
                }
            }
        }
        return -1;
    }
};

void main() {
    std::vector<int> nodes = {0, 1, 2, 3, 4, 5, 6};
    Graph graph(nodes);
    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 6);
    graph.add_edge(0, 3);
    graph.add_edge(3, 6);
    ShortestPathFinder spf(graph);
    int result = spf.bfs(0, 6);
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}