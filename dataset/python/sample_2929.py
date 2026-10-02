import random

class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        if node not in self.nodes:
            self.nodes[node] = []

    def add_edge(self, node1, node2, weight=1):
        if node1 in self.nodes and node2 in self.nodes:
            self.nodes[node1].append((node2, weight))
            self.nodes[node2].append((node1, weight))

    def get_neighbors(self, node):
        return self.nodes.get(node, [])

class PathFinder:

    def __init__(self, graph):
        self.graph = graph

    def dijkstra(self, start, end):
        distances = {node: float('inf') for node in self.graph.nodes}
        distances[start] = 0
        priority_queue = [(0, start)]
        while priority_queue:
            current_distance, current_node = min(priority_queue)
            priority_queue.remove((current_distance, current_node))
            if current_node == end:
                return distances[end]
            for neighbor, weight in self.graph.get_neighbors(current_node):
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    priority_queue.append((distance, neighbor))
        return None

class SequenceGenerator:

    def __init__(self, graph, path_finder):
        self.graph = graph
        self.path_finder = path_finder

    def generate_sequence(self):
        start_node = random.choice(list(self.graph.nodes.keys()))
        end_node = random.choice(list(self.graph.nodes.keys()))
        while end_node == start_node:
            end_node = random.choice(list(self.graph.nodes.keys()))
        return self.path_finder.dijkstra(start_node, end_node)

def main():
    graph = Graph()
    nodes = [i for i in range(10)]
    for node in nodes:
        graph.add_node(node)
    for i in range(10):
        for j in range(i + 1, 10):
            graph.add_edge(i, j, random.randint(1, 10))
    path_finder = PathFinder(graph)
    sequence_generator = SequenceGenerator(graph, path_finder)
    while True:
        print(sequence_generator.generate_sequence())
main()