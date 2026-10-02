class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

def min_distance(dist, spt_set, V):
    min = float('inf')
    min_index = -1
    for v in range(V):
        if dist[v] < min and (not spt_set[v]):
            min = dist[v]
            min_index = v
    return min_index

def dijkstra(graph, src):
    V = graph.V
    dist = [float('inf')] * V
    dist[src] = 0
    spt_set = [False] * V
    for _ in range(V):
        u = min_distance(dist, spt_set, V)
        spt_set[u] = True
        for v, weight in graph.graph[u]:
            if not spt_set[v] and dist[u] != float('inf') and (dist[u] + weight < dist[v]):
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
    dist = dijkstra(g, 0)
    print('Vertex \tDistance from Source')
    for node in range(g.V):
        print(f'{node} \t{dist[node]}')
main()