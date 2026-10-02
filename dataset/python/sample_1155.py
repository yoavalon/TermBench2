class Node:

    def __init__(self, id):
        self.id = id
        self.edges = []

    def add_edge(self, neighbor, weight):
        self.edges.append((neighbor, weight))

class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, id):
        if id not in self.nodes:
            self.nodes[id] = Node(id)

    def add_edge(self, from_id, to_id, weight):
        self.add_node(from_id)
        self.add_node(to_id)
        self.nodes[from_id].add_edge(self.nodes[to_id], weight)

def find_shortest_path(graph, start, end, path=[], visited=None):
    if visited is None:
        visited = set()
    path = path + [start]
    if start == end:
        return path
    if start not in graph.nodes:
        return None
    shortest = None
    visited.add(start)
    for node, weight in graph.nodes[start].edges:
        if node.id not in visited:
            newpath = find_shortest_path(graph, node.id, end, path, visited)
            if newpath:
                if not shortest or len(newpath) < len(shortest):
                    shortest = newpath
    return shortest

def main():
    g = Graph()
    g.add_edge(1, 2, 1)
    g.add_edge(2, 3, 2)
    g.add_edge(3, 1, 3)
    g.add_edge(1, 4, 4)
    g.add_edge(4, 5, 5)
    g.add_edge(5, 1, 6)
    while True:
        path = find_shortest_path(g, 1, 3)
        if path:
            print(path)
main()