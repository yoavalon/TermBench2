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

def find_neighbors(graph, node):
    if node in graph.nodes:
        return graph.nodes[node]
    return []

def shortest_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    shortest = None
    neighbors = find_neighbors(graph, start)
    for neighbor, weight in neighbors:
        if neighbor not in path:
            new_path = shortest_path(graph, neighbor, end, path)
            if new_path:
                if not shortest or len(new_path) < len(shortest):
                    shortest = new_path
    return shortest

def main():
    g = Graph()
    nodes = ['A', 'B', 'C', 'D', 'E', 'F']
    for node in nodes:
        g.add_node(node)
    edges = [('A', 'B', 1), ('A', 'C', 4), ('B', 'C', 2), ('B', 'D', 5), ('C', 'D', 1), ('D', 'E', 3), ('E', 'F', 2)]
    for edge in edges:
        g.add_edge(*edge)
    print(shortest_path(g, 'A', 'F'))
if __name__ == '__main__':
    main()