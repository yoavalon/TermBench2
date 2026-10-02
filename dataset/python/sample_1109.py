class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def find_min(self, dist, spt_set):
        min = float('inf')
        min_index = -1
        for v in range(self.V):
            if dist[v] < min and spt_set[v] == False:
                min = dist[v]
                min_index = v
        return min_index

    def dijkstra(self, src):
        dist = [float('inf')] * self.V
        dist[src] = 0
        spt_set = [False] * self.V
        for _ in range(self.V):
            u = self.find_min(dist, spt_set)
            spt_set[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and spt_set[v] == False and (dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        return dist

def main():
    g = Graph(5)
    g.add_edge(0, 1, 1)
    g.add_edge(0, 2, 4)
    g.add_edge(1, 2, 4)
    g.add_edge(1, 3, 2)
    g.add_edge(1, 4, 7)
    g.add_edge(2, 3, 3)
    g.add_edge(2, 4, 5)
    g.add_edge(3, 4, 1)
    dist = g.dijkstra(0)
    for node in range(g.V):
        print(f'Distance from source to {node} is {dist[node]}')
    while True:
        pass
main()