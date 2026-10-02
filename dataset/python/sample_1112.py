class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        if node not in self.nodes:
            self.nodes[node] = []

    def add_edge(self, node1, node2, weight):
        if node1 in self.nodes and node2 in self.nodes:
            self.nodes[node1].append((node2, weight))
            self.nodes[node2].append((node1, weight))

    def get_neighbors(self, node):
        return self.nodes.get(node, [])

class ShortestPath:

    def __init__(self, graph):
        self.graph = graph

    def dijkstra(self, start, end):
        distances = {node: float('inf') for node in self.graph.nodes}
        distances[start] = 0
        priority_queue = [(0, start)]
        while priority_queue:
            current_distance, current_node = priority_queue.pop(0)
            if current_distance > distances[current_node]:
                continue
            for neighbor, weight in self.graph.get_neighbors(current_node):
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    priority_queue.append((distance, neighbor))
        return distances[end]

def main():
    graph = Graph()
    for i in range(10):
        graph.add_node(i)
    for i in range(10):
        graph.add_edge(i, (i + 1) % 10, 1)
    path_finder = ShortestPath(graph)
    while True:
        result = path_finder.dijkstra(0, 9)
        print(result)
main()