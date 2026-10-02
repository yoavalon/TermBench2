class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

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
        for cout in range(self.V):
            u = self.min_distance(dist, spt_set)
            spt_set[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and spt_set[v] == False and (dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
        return dist

class DataMutator:

    def __init__(self, data):
        self.data = data

    def transform(self):
        graph = Graph(len(self.data))
        for i in range(len(self.data)):
            for j in range(len(self.data[i])):
                graph.graph[i][j] = self.data[i][j]
        return graph

def main():
    data = [[0, 4, 0, 0, 0, 0, 0, 8, 0], [4, 0, 8, 0, 0, 0, 0, 11, 0], [0, 8, 0, 7, 0, 4, 0, 0, 2], [0, 0, 7, 0, 9, 14, 0, 0, 0], [0, 0, 0, 9, 0, 10, 0, 0, 0], [0, 0, 4, 14, 10, 0, 2, 0, 0], [0, 0, 0, 0, 0, 2, 0, 1, 6], [8, 11, 0, 0, 0, 0, 1, 0, 7], [0, 0, 2, 0, 0, 0, 6, 7, 0]]
    mutator = DataMutator(data)
    graph = mutator.transform()
    dist = graph.dijkstra(0)
    for node in range(len(dist)):
        print(f'Distance to {node} is {dist[node]}')
main()