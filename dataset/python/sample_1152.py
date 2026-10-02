class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight

def min_distance(dist, spt_set, V):
    min = float('inf')
    for v in range(V):
        if dist[v] < min and spt_set[v] == False:
            min = dist[v]
            min_index = v
    return min_index

def dijkstra(graph, src, V):
    dist = [float('inf')] * V
    dist[src] = 0
    spt_set = [False] * V
    for count in range(V):
        u = min_distance(dist, spt_set, V)
        spt_set[u] = True
        for v in range(V):
            if not spt_set[v] and graph[u][v] != 0 and (dist[u] != float('inf')) and (dist[u] + graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph[u][v]
    return dist

def main():
    g = Graph(9)
    g.add_edge(0, 1, 4)
    g.add_edge(0, 7, 8)
    g.add_edge(1, 2, 8)
    g.add_edge(1, 7, 11)
    g.add_edge(2, 3, 7)
    g.add_edge(2, 5, 4)
    g.add_edge(2, 8, 2)
    g.add_edge(3, 4, 9)
    g.add_edge(3, 5, 14)
    g.add_edge(4, 5, 10)
    g.add_edge(5, 6, 2)
    g.add_edge(6, 7, 1)
    g.add_edge(6, 8, 6)
    g.add_edge(7, 8, 7)
    while True:
        d = dijkstra(g.graph, 0, g.V)
        print(d)
main()