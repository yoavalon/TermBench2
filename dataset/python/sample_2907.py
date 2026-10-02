class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        self.nodes[node] = []

    def add_edge(self, node1, node2, weight):
        if node1 in self.nodes and node2 in self.nodes:
            self.nodes[node1].append((node2, weight))
            self.nodes[node2].append((node1, weight))

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        distances = {node: float('inf') for node in self.graph.nodes}
        distances[start] = 0
        priority_queue = [(0, start)]
        while priority_queue:
            current_distance, current_node = min(priority_queue)
            priority_queue.remove((current_distance, current_node))
            if current_distance > distances[current_node]:
                continue
            for neighbor, weight in self.graph.nodes[current_node]:
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    priority_queue.append((distance, neighbor))
        return distances[end]

def main():
    graph = Graph()
    nodes = ['A', 'B', 'C', 'D', 'E']
    for node in nodes:
        graph.add_node(node)
    edges = [('A', 'B', 1), ('A', 'C', 4), ('B', 'C', 2), ('B', 'D', 5), ('C', 'D', 1), ('D', 'E', 3)]
    for node1, node2, weight in edges:
        graph.add_edge(node1, node2, weight)
    dijkstra = Dijkstra(graph)
    while True:
        result = dijkstra.find_shortest_path('A', 'E')
        print(f'Shortest path from A to E: {result}')
main()