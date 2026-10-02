class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def min_distance(self, dist, spt_set):
        min = float('inf')
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
            u = self.min_distance(dist, spt_set)
            spt_set[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and spt_set[v] == False and (dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        return dist

class Router:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_paths(self, start):
        return self.graph.dijkstra(start)

class Network:

    def __init__(self, vertices):
        self.graph = Graph(vertices)
        self.router = Router(self.graph)

    def connect_nodes(self, u, v, weight):
        self.graph.add_edge(u, v, weight)

    def shortest_paths_from(self, node):
        return self.router.find_shortest_paths(node)

def main():
    network = Network(5)
    network.connect_nodes(0, 1, 10)
    network.connect_nodes(0, 3, 5)
    network.connect_nodes(1, 2, 1)
    network.connect_nodes(1, 3, 2)
    network.connect_nodes(1, 4, 3)
    network.connect_nodes(2, 4, 1)
    network.connect_nodes(3, 2, 4)
    network.connect_nodes(3, 4, 2)
    network.connect_nodes(4, 2, 6)
    network.connect_nodes(4, 0, 7)
    paths = network.shortest_paths_from(0)
    print(paths)
if __name__ == '__main__':
    main()