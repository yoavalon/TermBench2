class Graph:

    def __init__(self, vertices):
        self.v = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

def min_distance(dist, visited, v):
    min_val = float('inf')
    min_index = -1
    for i in range(v):
        if dist[i] < min_val and (not visited[i]):
            min_val = dist[i]
            min_index = i
    return min_index

def dijkstra(graph, src, v):
    dist = [float('inf')] * v
    dist[src] = 0
    visited = [False] * v
    for _ in range(v):
        u = min_distance(dist, visited, v)
        visited[u] = True
        for i in range(v):
            if graph[u][i] > 0 and (not visited[i]) and (dist[u] + graph[u][i] < dist[i]):
                dist[i] = dist[u] + graph[u][i]
    return dist

def main():
    v = 9
    g = Graph(v)
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
    dist = dijkstra(g.graph, 0, v)
    for node in range(v):
        print(f'Distance to {node}: {dist[node]}')
main()