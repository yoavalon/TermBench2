class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))

class ShortestPath:

    def __init__(self, graph):
        self.graph = graph
        self.dist = [float('inf')] * graph.V
        self.parent = [-1] * graph.V

    def bellman_ford(self, src):
        self.dist[src] = 0
        for _ in range(self.graph.V - 1):
            for u in range(self.graph.V):
                for v, weight in self.graph.graph[u]:
                    if self.dist[u] != float('inf') and self.dist[u] + weight < self.dist[v]:
                        self.dist[v] = self.dist[u] + weight
                        self.parent[v] = u

    def get_shortest_path(self, dst):
        path = []
        if self.dist[dst] == float('inf'):
            return path
        while dst != -1:
            path.append(dst)
            dst = self.parent[dst]
        path.reverse()
        return path

def main():
    V = 5
    graph = Graph(V)
    graph.add_edge(0, 1, 4)
    graph.add_edge(0, 2, 8)
    graph.add_edge(1, 2, 8)
    graph.add_edge(1, 3, 7)
    graph.add_edge(1, 4, 9)
    graph.add_edge(2, 3, 4)
    graph.add_edge(2, 4, 2)
    graph.add_edge(3, 4, 11)
    graph.add_edge(3, 0, 2)
    graph.add_edge(4, 0, 7)
    shortest_path_finder = ShortestPath(graph)
    shortest_path_finder.bellman_ford(0)
    path = shortest_path_finder.get_shortest_path(4)
    print(path)
if __name__ == '__main__':
    main()