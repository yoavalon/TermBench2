class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

def dijkstra(graph, src):
    dist = [float('inf')] * graph.V
    dist[src] = 0
    sptSet = [False] * graph.V
    for _ in range(graph.V):
        u = min_distance(dist, sptSet, graph.V)
        sptSet[u] = True
        for v in range(graph.V):
            if not sptSet[v] and graph.graph[u][v] != 0 and (dist[u] != float('inf')) and (dist[u] + graph.graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph.graph[u][v]
    return dist

def min_distance(dist, sptSet, V):
    min = float('inf')
    for v in range(V):
        if dist[v] < min and (not sptSet[v]):
            min = dist[v]
            min_index = v
    return min_index

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
    dist = dijkstra(g, 0)
    for node in range(g.V):
        print(f'Distance from 0 to {node} is {dist[node]}')
main()