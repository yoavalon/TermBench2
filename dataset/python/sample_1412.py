class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, node1, node2, weight):
        if node1 not in self.edges:
            self.edges[node1] = {}
        if node2 not in self.edges:
            self.edges[node2] = {}
        self.edges[node1][node2] = weight
        self.edges[node2][node1] = weight

    def get_neighbors(self, node):
        return self.edges.get(node, {})

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        distances = {node: float('inf') for node in self.graph.edges}
        distances[start] = 0
        unvisited = list(self.graph.edges.keys())
        while unvisited:
            current = min(unvisited, key=lambda node: distances[node])
            unvisited.remove(current)
            if current == end:
                break
            for neighbor, weight in self.graph.get_neighbors(current).items():
                distance = distances[current] + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
        return distances[end]

def main():
    g = Graph()
    g.add_edge('A', 'B', 1)
    g.add_edge('B', 'C', 2)
    g.add_edge('C', 'D', 3)
    g.add_edge('A', 'D', 10)
    g.add_edge('B', 'D', 4)
    dijkstra = Dijkstra(g)
    result = dijkstra.find_shortest_path('A', 'D')
    print(result)
main()