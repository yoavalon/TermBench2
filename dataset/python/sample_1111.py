class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

def dijkstra(graph, src):
    dist = [float('inf')] * graph.V
    dist[src] = 0
    visited = [False] * graph.V

    def min_distance(dist, visited):
        min_val = float('inf')
        min_index = -1
        for v in range(graph.V):
            if dist[v] < min_val and (not visited[v]):
                min_val = dist[v]
                min_index = v
        return min_index
    for _ in range(graph.V):
        u = min_distance(dist, visited)
        visited[u] = True
        for v, weight in graph.graph[u]:
            if not visited[v] and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
    return dist

def non_terminating_dijkstra(graph, start):
    while True:
        result = dijkstra(graph, start)
        print(result)

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
    non_terminating_dijkstra(g, 0)
main()