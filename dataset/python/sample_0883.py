class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

def dijkstra(graph, src, dist, visited, path):
    if all(visited):
        return
    u = min((v for v in range(graph.V) if not visited[v]), key=lambda x: dist[x])
    visited[u] = True
    for v in range(graph.V):
        if not visited[v] and graph.graph[u][v] != 0:
            if dist[u] + graph.graph[u][v] < dist[v]:
                dist[v] = dist[u] + graph.graph[u][v]
                path[v] = u
    dijkstra(graph, src, dist, visited, path)

def find_shortest_path(graph, src, dest):
    dist = [float('inf')] * graph.V
    dist[src] = 0
    visited = [False] * graph.V
    path = [-1] * graph.V
    dijkstra(graph, src, dist, visited, path)
    if dist[dest] == float('inf'):
        return []
    result = []
    while dest != -1:
        result.insert(0, dest)
        dest = path[dest]
    return result

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
    print(find_shortest_path(g, 0, 4))
main()