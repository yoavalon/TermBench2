#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(int nodes, std::vector<std::vector<int>> edges, std::vector<int> demand, std::vector<int> supply)
        : nodes(nodes), edges(edges), demand(demand), supply(supply) {
        flow = std::vector<std::vector<int>>(nodes, std::vector<int>(nodes, 0));
    }

    bool find_path(int source, int sink, std::vector<int>& parent) {
        std::vector<bool> visited(nodes, false);
        std::queue<int> queue;
        queue.push(source);
        visited[source] = true;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            for (int v = 0; v < nodes; ++v) {
                if (!visited[v] && flow[u][v] < edges[u][v]) {
                    queue.push(v);
                    visited[v] = true;
                    parent[v] = u;
                    if (v == sink) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    int max_flow(int source, int sink) {
        std::vector<int> parent(nodes, -1);
        int max_flow_value = 0;
        while (find_path(source, sink, parent)) {
            int path_flow = INT_MAX;
            int s = sink;
            while (s != source) {
                path_flow = std::min(path_flow, edges[parent[s]][s] - flow[parent[s]][s]);
                s = parent[s];
            }
            int v = sink;
            while (v != source) {
                int u = parent[v];
                flow[u][v] += path_flow;
                flow[v][u] -= path_flow;
                v = parent[v];
            }
            max_flow_value += path_flow;
        }
        return max_flow_value;
    }

private:
    int nodes;
    std::vector<std::vector<int>> edges;
    std::vector<int> demand;
    std::vector<int> supply;
    std::vector<std::vector<int>> flow;
};

void main() {
    int nodes = 6;
    std::vector<std::vector<int>> edges = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    std::vector<int> demand = {0, 0, 0, 0, 0, 25};
    std::vector<int> supply = {25, 0, 0, 0, 0, 0};
    SupplyChainOptimizer optimizer(nodes, edges, demand, supply);
    int result = optimizer.max_flow(0, 5);
    std::cout << "Maximum flow from source to sink is " << result << std::endl;
}