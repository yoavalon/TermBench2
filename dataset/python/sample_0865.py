class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

    def dijkstra(self, start):
        distance = [float('inf')] * self.V
        distance[start] = 0
        visited = [False] * self.V

        def min_distance(dist, visited):
            min_dist = float('inf')
            min_index = -1
            for v in range(self.V):
                if not visited[v] and dist[v] < min_dist:
                    min_dist = dist[v]
                    min_index = v
            return min_index
        for _ in range(self.V):
            u = min_distance(distance, visited)
            visited[u] = True
            for v, weight in self.graph[u]:
                if not visited[v] and distance[u] + weight < distance[v]:
                    distance[v] = distance[u] + weight
        return distance

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
    start_vertex = 0
    distances = g.dijkstra(start_vertex)
    for i in range(g.V):
        print(f'Distance from {start_vertex} to {i} is {distances[i]}')
main()