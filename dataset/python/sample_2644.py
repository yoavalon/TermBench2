class Graph:

    def __init__(self, nodes):
        self.nodes = nodes
        self.edges = {}

    def add_edge(self, u, v, weight):
        if u not in self.edges:
            self.edges[u] = {}
        self.edges[u][v] = weight

    def get_neighbors(self, node):
        return self.edges.get(node, {})

class Dijkstra:

    def __init__(self, graph, start):
        self.graph = graph
        self.start = start
        self.distances = {node: float('inf') for node in graph.nodes}
        self.distances[start] = 0
        self.priority_queue = [(0, start)]

    def extract_min(self):
        min_distance = float('inf')
        min_node = None
        for node, distance in self.priority_queue:
            if distance < min_distance:
                min_distance = distance
                min_node = node
        self.priority_queue.remove((min_distance, min_node))
        return min_node

    def update_distances(self, current, neighbors):
        for neighbor, weight in neighbors:
            new_distance = self.distances[current] + weight
            if new_distance < self.distances[neighbor]:
                self.distances[neighbor] = new_distance
                self.priority_queue.append((new_distance, neighbor))

    def run(self):
        while self.priority_queue:
            current = self.extract_min()
            neighbors = [(neighbor, weight) for neighbor, weight in self.graph.get_neighbors(current).items()]
            self.update_distances(current, neighbors)
        return self.distances

def main():
    nodes = ['A', 'B', 'C', 'D', 'E']
    graph = Graph(nodes)
    graph.add_edge('A', 'B', 1)
    graph.add_edge('A', 'C', 4)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('B', 'D', 5)
    graph.add_edge('C', 'D', 1)
    graph.add_edge('D', 'E', 3)
    dijkstra = Dijkstra(graph, 'A')
    shortest_paths = dijkstra.run()
    print(shortest_paths)
if __name__ == '__main__':
    main()