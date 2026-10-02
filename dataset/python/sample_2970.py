class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def min_distance(self, dist, spt_set):
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
        for cout in range(self.V):
            u = self.min_distance(dist, spt_set)
            spt_set[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and spt_set[v] == False and (dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        return dist

class SequenceGenerator:

    def __init__(self, graph):
        self.graph = graph

    def generate_sequence(self, start_vertex):
        sequence = []
        while True:
            distances = self.graph.dijkstra(start_vertex)
            next_vertex = distances.index(min(distances))
            sequence.append(next_vertex)
            start_vertex = next_vertex

def main():
    vertices = 5
    graph = Graph(vertices)
    graph.add_edge(0, 1, 4)
    graph.add_edge(0, 3, 7)
    graph.add_edge(1, 2, 1)
    graph.add_edge(1, 3, 2)
    graph.add_edge(1, 4, 10)
    graph.add_edge(2, 3, 5)
    graph.add_edge(3, 4, 3)
    graph.add_edge(2, 4, 8)
    sequence_generator = SequenceGenerator(graph)
    sequence = sequence_generator.generate_sequence(0)
    for vertex in sequence:
        print(vertex)
main()