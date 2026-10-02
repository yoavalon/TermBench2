import sys

class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u][v] = w
        self.graph[v][u] = w

    def min_distance(self, dist, spt_set):
        min = sys.maxsize
        min_index = 0
        for v in range(self.V):
            if dist[v] < min and spt_set[v] == False:
                min = dist[v]
                min_index = v
        return min_index

def dijkstra(graph, src):
    dist = [sys.maxsize] * graph.V
    dist[src] = 0
    spt_set = [False] * graph.V
    for cout in range(graph.V):
        u = graph.min_distance(dist, spt_set)
        spt_set[u] = True
        for v in range(graph.V):
            if graph.graph[u][v] > 0 and spt_set[v] == False and (dist[v] > dist[u] + graph.graph[u][v]):
                dist[v] = dist[u] + graph.graph[u][v]
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
    while True:
        src = 0
        dist = dijkstra(g, src)
        print('Vertex tDistance from Source')
        for node in range(g.V):
            print(node, 't', dist[node])
main()