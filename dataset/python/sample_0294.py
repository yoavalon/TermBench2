import heapq

class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, from_node, to_node, weight):
        if from_node in self.edges:
            self.edges[from_node].append((to_node, weight))
        else:
            self.edges[from_node] = [(to_node, weight)]

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        distances = {node: float('inf') for node in self.graph.edges}
        distances[start] = 0
        priority_queue = [(0, start)]
        visited = set()
        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)
            if current_node in visited:
                continue
            visited.add(current_node)
            if current_node == end:
                return distances[end]
            for neighbor, weight in self.graph.edges.get(current_node, []):
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(priority_queue, (distance, neighbor))
        return float('inf')

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('A', 'C', 4)
    graph.add_edge('C', 'D', 1)
    graph.add_edge('A', 'D', 7)
    dijkstra = Dijkstra(graph)
    shortest_path_length = dijkstra.find_shortest_path('A', 'D')
    print('Shortest path length from A to D:', shortest_path_length)
if __name__ == '__main__':
    main()