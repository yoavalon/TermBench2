class Graph:

    def __init__(self):
        self.adj_list = {}

    def add_vertex(self, vertex):
        if vertex not in self.adj_list:
            self.adj_list[vertex] = []

    def add_edge(self, vertex1, vertex2, weight):
        if vertex1 in self.adj_list and vertex2 in self.adj_list:
            self.adj_list[vertex1].append((vertex2, weight))
            self.adj_list[vertex2].append((vertex1, weight))

    def get_neighbors(self, vertex):
        return self.adj_list.get(vertex, [])

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        distances = {vertex: float('inf') for vertex in self.graph.adj_list}
        distances[start] = 0
        priority_queue = [(0, start)]
        while priority_queue:
            current_distance, current_vertex = min(priority_queue)
            priority_queue.remove((current_distance, current_vertex))
            if current_distance > distances[current_vertex]:
                continue
            for neighbor, weight in self.graph.get_neighbors(current_vertex):
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    priority_queue.append((distance, neighbor))
        return distances[end]

def main():
    g = Graph()
    g.add_vertex('A')
    g.add_vertex('B')
    g.add_vertex('C')
    g.add_vertex('D')
    g.add_vertex('E')
    g.add_edge('A', 'B', 1)
    g.add_edge('B', 'C', 2)
    g.add_edge('C', 'D', 3)
    g.add_edge('D', 'E', 4)
    g.add_edge('A', 'E', 10)
    dijkstra = Dijkstra(g)
    result = dijkstra.find_shortest_path('A', 'E')
    print(result)
if __name__ == '__main__':
    main()