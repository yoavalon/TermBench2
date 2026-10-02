class SupplyChainOptimizer:

    def __init__(self, nodes, edges, demand, supply):
        self.nodes = nodes
        self.edges = edges
        self.demand = demand
        self.supply = supply
        self.flow = [[0 for _ in range(nodes)] for _ in range(nodes)]

    def find_path(self, source, sink, parent):
        visited = [False] * self.nodes
        queue = [source]
        visited[source] = True
        while queue:
            u = queue.pop(0)
            for v in range(self.nodes):
                if not visited[v] and self.flow[u][v] < self.edges[u][v]:
                    queue.append(v)
                    visited[v] = True
                    parent[v] = u
                    if v == sink:
                        return True
        return False

    def max_flow(self, source, sink):
        parent = [-1] * self.nodes
        max_flow_value = 0
        while self.find_path(source, sink, parent):
            path_flow = float('Inf')
            s = sink
            while s != source:
                path_flow = min(path_flow, self.edges[parent[s]][s] - self.flow[parent[s]][s])
                s = parent[s]
            v = sink
            while v != source:
                u = parent[v]
                self.flow[u][v] += path_flow
                self.flow[v][u] -= path_flow
                v = parent[v]
            max_flow_value += path_flow
        return max_flow_value

def main():
    nodes = 6
    edges = [[0, 16, 13, 0, 0, 0], [0, 0, 10, 12, 0, 0], [0, 4, 0, 0, 14, 0], [0, 0, 9, 0, 0, 20], [0, 0, 0, 7, 0, 4], [0, 0, 0, 0, 0, 0]]
    demand = [0, 0, 0, 0, 0, 25]
    supply = [25, 0, 0, 0, 0, 0]
    optimizer = SupplyChainOptimizer(nodes, edges, demand, supply)
    result = optimizer.max_flow(0, 5)
    print('Maximum flow from source to sink is', result)
if __name__ == '__main__':
    main()