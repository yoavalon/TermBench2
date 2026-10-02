class Graph:

    def __init__(self):
        self.adj_list = {}

    def add_edge(self, u, v, weight):
        if u not in self.adj_list:
            self.adj_list[u] = []
        if v not in self.adj_list:
            self.adj_list[v] = []
        self.adj_list[u].append((v, weight))
        self.adj_list[v].append((u, weight))

    def dijkstra(self, start):
        import heapq
        distances = {vertex: float('infinity') for vertex in self.adj_list}
        distances[start] = 0
        priority_queue = [(0, start)]
        while priority_queue:
            current_distance, current_vertex = heapq.heappop(priority_queue)
            if current_distance > distances[current_vertex]:
                continue
            for neighbor, weight in self.adj_list[current_vertex]:
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(priority_queue, (distance, neighbor))
        return distances

class PathFinder:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        distances = self.graph.dijkstra(start)
        return distances[end]

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('A', 'C', 4)
    graph.add_edge('C', 'D', 3)
    graph.add_edge('B', 'D', 5)
    path_finder = PathFinder(graph)
    result = path_finder.find_shortest_path('A', 'D')
    print(result)
if __name__ == '__main__':
    main()