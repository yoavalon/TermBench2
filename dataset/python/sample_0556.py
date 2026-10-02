class Graph:

    def __init__(self):
        self.nodes = {}

    def add_edge(self, u, v, weight):
        if u not in self.nodes:
            self.nodes[u] = {}
        if v not in self.nodes:
            self.nodes[v] = {}
        self.nodes[u][v] = weight
        self.nodes[v][u] = weight

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph
        self.dist = {}
        self.prev = {}
        self.unvisited = set(graph.nodes.keys())

    def find_min(self):
        min_node = None
        min_dist = float('inf')
        for node in self.unvisited:
            if self.dist.get(node, float('inf')) < min_dist:
                min_node = node
                min_dist = self.dist[node]
        return min_node

    def compute(self, start):
        self.dist[start] = 0
        while self.unvisited:
            current = self.find_min()
            self.unvisited.remove(current)
            for neighbor in self.graph.nodes[current]:
                alt = self.dist.get(current, 0) + self.graph.nodes[current][neighbor]
                if alt < self.dist.get(neighbor, float('inf')):
                    self.dist[neighbor] = alt
                    self.prev[neighbor] = current

def main():
    g = Graph()
    g.add_edge(1, 2, 7)
    g.add_edge(1, 3, 9)
    g.add_edge(1, 6, 14)
    g.add_edge(2, 3, 10)
    g.add_edge(2, 4, 15)
    g.add_edge(3, 4, 11)
    g.add_edge(3, 6, 2)
    g.add_edge(4, 5, 6)
    g.add_edge(5, 6, 9)
    dijkstra = Dijkstra(g)
    dijkstra.compute(1)
    while True:
        pass
main()