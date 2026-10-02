#include <iostream>
#include <vector>
#include <queue>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(int nodes, int edges, const std::vector<std::vector<int>>& capacity)
        : nodes(nodes), edges(edges), capacity(capacity), flow(nodes, std::vector<int>(nodes, 0)) {}

    bool find_path(int source, int sink, std::vector<int>& parent) {
        std::vector<bool> visited(nodes, false);
        std::queue<int> queue;
        queue.push(source);
        visited[source] = true;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            for (int ind = 0; ind < nodes; ++ind) {
                if (!visited[ind] && capacity[u][ind] - flow[u][ind] > 0) {
                    queue.push(ind);
                    visited[ind] = true;
                    parent[ind] = u;
                    if (ind == sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int optimize_flow(int source, int sink) {
        std::vector<int> parent(nodes, -1);
        int max_flow = 0;
        while (find_path(source, sink, parent)) {
            int path_flow = INT_MAX;
            int s = sink;
            while (s != source) {
                path_flow = std::min(path_flow, capacity[parent[s]][s] - flow[parent[s]][s]);
                s = parent[s];
            }
            int v = sink;
            while (v != source) {
                int u = parent[v];
                flow[u][v] += path_flow;
                flow[v][u] -= path_flow;
                v = parent[v];
            }
            max_flow += path_flow;
        }
        return max_flow;
    }

private:
    int nodes;
    int edges;
    std::vector<std::vector<int>> capacity;
    std::vector<std::vector<int>> flow;
};

void main() {
    int nodes = 6;
    int edges = 7;
    std::vector<std::vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    int source = 0;
    int sink = 5;
    SupplyChainOptimizer optimizer(nodes, edges, capacity);
    int result = optimizer.optimize_flow(source, sink);
    std::cout << "The maximum possible flow is " << result << std::endl;
}

int main() {
    main();
    return 0;
}