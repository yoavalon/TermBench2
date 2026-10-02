class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, u, v, weight):
        if u not in self.edges:
            self.edges[u] = []
        self.edges[u].append((v, weight))

    def get_neighbors(self, node):
        return self.edges.get(node, [])

class PathFinder:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        distances = {node: float('inf') for node in self.graph.edges}
        distances[start] = 0
        queue = [(0, start)]
        while queue:
            current_dist, current_node = queue.pop(0)
            if current_dist > distances[current_node]:
                continue
            for neighbor, weight in self.graph.get_neighbors(current_node):
                distance = current_dist + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    queue.append((distance, neighbor))
        return distances[end]

class Mutator:

    def __init__(self, path_finder, target_node):
        self.path_finder = path_finder
        self.target_node = target_node

    def mutate_graph(self):
        for node in self.path_finder.graph.edges:
            for neighbor, weight in self.path_finder.graph.get_neighbors(node):
                if weight > 0:
                    self.path_finder.graph.add_edge(neighbor, node, weight - 1)
        return self.path_finder.find_shortest_path('A', self.target_node)

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('C', 'D', 3)
    graph.add_edge('D', 'A', 1)
    graph.add_edge('B', 'D', 4)
    path_finder = PathFinder(graph)
    mutator = Mutator(path_finder, 'D')
    print(mutator.mutate_graph())
if __name__ == '__main__':
    main()