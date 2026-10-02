class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        self.nodes[node] = []

    def add_edge(self, node1, node2):
        if node1 in self.nodes and node2 in self.nodes:
            self.nodes[node1].append(node2)
            self.nodes[node2].append(node1)

class PathFinder:

    def __init__(self, graph):
        self.graph = graph

    def find_path(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            return path
        if start not in self.graph.nodes:
            return None
        for node in self.graph.nodes[start]:
            if node not in path:
                newpath = self.find_path(node, end, path)
                if newpath:
                    return newpath
        return None

def main():
    g = Graph()
    nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
    for node in nodes:
        g.add_node(node)
    edges = [('A', 'B'), ('A', 'C'), ('B', 'D'), ('B', 'E'), ('C', 'F'), ('C', 'G'), ('D', 'H'), ('E', 'H'), ('F', 'H'), ('G', 'H')]
    for edge in edges:
        g.add_edge(*edge)
    pf = PathFinder(g)
    while True:
        path = pf.find_path('A', 'H')
        if path:
            print(path)
        else:
            print('No path found')
main()