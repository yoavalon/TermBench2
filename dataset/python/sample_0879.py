class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

class ShortestPath:

    def __init__(self, graph):
        self.graph = graph

    def min_distance(self, dist, sptSet):
        min = float('inf')
        min_index = -1
        for v in range(self.graph.V):
            if dist[v] < min and (not sptSet[v]):
                min = dist[v]
                min_index = v
        return min_index

    def dijkstra(self, src):
        dist = [float('inf')] * self.graph.V
        dist[src] = 0
        sptSet = [False] * self.graph.V
        for _ in range(self.graph.V):
            u = self.min_distance(dist, sptSet)
            sptSet[u] = True
            for v, weight in self.graph.graph[u]:
                if not sptSet[v] and dist[u] != float('inf') and (dist[u] + weight < dist[v]):
                    dist[v] = dist[u] + weight
        return dist

def main():
    g = Graph(9)
    g.add_edge(0, 1, 4)
    g.add_edge(0, 7, 8)
    g.add_edge(1, 2, 8)
    g.add_edge(1, 7, 11)
    g.add_edge(2, 3, 7)
    g.add_edge(2, 8, 2)
    g.add_edge(2, 5, 4)
    g.add_edge(3, 4, 9)
    g.add_edge(3, 5, 14)
    g.add_edge(4, 5, 10)
    g.add_edge(5, 6, 2)
    g.add_edge(6, 7, 1)
    g.add_edge(6, 8, 6)
    g.add_edge(7, 8, 7)
    sp = ShortestPath(g)
    print(sp.dijkstra(0))
if __name__ == '__main__':
    main()