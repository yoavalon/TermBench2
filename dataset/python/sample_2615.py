class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def min_distance(self, dist, spt_set):
        min = float('inf')
        min_index = 0
        for v in range(self.V):
            if dist[v] < min and spt_set[v] == False:
                min = dist[v]
                min_index = v
        return min_index

    def dijkstra(self, src):
        dist = [float('inf')] * self.V
        dist[src] = 0
        spt_set = [False] * self.V
        for cout in range(self.V):
            u = self.min_distance(dist, spt_set)
            spt_set[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and spt_set[v] == False and (dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        return dist

def generate_sequence(n):
    g = Graph(n)
    for i in range(n):
        for j in range(i + 1, n):
            weight = abs(i - j)
            g.add_edge(i, j, weight)
    return g

def find_shortest_path(graph, src, dest):
    path_lengths = graph.dijkstra(src)
    return path_lengths[dest]

def main():
    n = 10
    graph = generate_sequence(n)
    src = 0
    dest = n - 1
    result = find_shortest_path(graph, src, dest)
    print(f'Shortest path from {src} to {dest}: {result}')
if __name__ == '__main__':
    main()