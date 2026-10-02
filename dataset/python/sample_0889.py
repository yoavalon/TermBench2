class SupplyChainOptimizer:

    def __init__(self, nodes, edges, capacity):
        self.nodes = nodes
        self.edges = edges
        self.capacity = capacity
        self.flow = [[0] * nodes for _ in range(nodes)]

    def find_path(self, source, sink, parent):
        visited = [False] * self.nodes
        queue = [source]
        visited[source] = True
        while queue:
            u = queue.pop(0)
            for ind in range(self.nodes):
                if not visited[ind] and self.capacity[u][ind] - self.flow[u][ind] > 0:
                    queue.append(ind)
                    visited[ind] = True
                    parent[ind] = u
                    if ind == sink:
                        return True
        return False

    def optimize_flow(self, source, sink):
        parent = [-1] * self.nodes
        max_flow = 0
        while self.find_path(source, sink, parent):
            path_flow = float('Inf')
            s = sink
            while s != source:
                path_flow = min(path_flow, self.capacity[parent[s]][s] - self.flow[parent[s]][s])
                s = parent[s]
            v = sink
            while v != source:
                u = parent[v]
                self.flow[u][v] += path_flow
                self.flow[v][u] -= path_flow
                v = parent[v]
            max_flow += path_flow
        return max_flow

def main():
    nodes = 6
    edges = 7
    capacity = [[0, 16, 13, 0, 0, 0], [0, 0, 10, 12, 0, 0], [0, 4, 0, 0, 14, 0], [0, 0, 9, 0, 0, 20], [0, 0, 0, 7, 0, 4], [0, 0, 0, 0, 0, 0]]
    source = 0
    sink = 5
    optimizer = SupplyChainOptimizer(nodes, edges, capacity)
    result = optimizer.optimize_flow(source, sink)
    print('The maximum possible flow is %d ' % result)
if __name__ == '__main__':
    main()