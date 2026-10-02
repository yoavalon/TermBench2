import math

class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, u, v, weight):
        if u not in self.edges:
            self.edges[u] = {}
        self.edges[u][v] = weight

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph
        self.distances = {}
        self.previous = {}

    def compute(self, start):
        unvisited = set(self.graph.edges.keys())
        for node in unvisited:
            self.distances[node] = math.inf
        self.distances[start] = 0
        while unvisited:
            current = min(unvisited, key=lambda node: self.distances[node])
            unvisited.remove(current)
            for neighbor, weight in self.graph.edges.get(current, {}).items():
                distance = self.distances[current] + weight
                if distance < self.distances[neighbor]:
                    self.distances[neighbor] = distance
                    self.previous[neighbor] = current

    def shortest_path(self, start, end):
        path = []
        while end is not None:
            path.append(end)
            end = self.previous.get(end)
        return path[::-1]

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1.0)
    graph.add_edge('A', 'C', 4.0)
    graph.add_edge('B', 'C', 2.0)
    graph.add_edge('B', 'D', 5.0)
    graph.add_edge('C', 'D', 1.0)
    dijkstra = Dijkstra(graph)
    dijkstra.compute('A')
    path = dijkstra.shortest_path('A', 'D')
    print('Shortest path:', path)
if __name__ == '__main__':
    main()