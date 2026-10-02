class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        self.nodes[node] = []

    def add_edge(self, node1, node2, weight):
        if node1 in self.nodes and node2 in self.nodes:
            self.nodes[node1].append((node2, weight))
            self.nodes[node2].append((node1, weight))

class PathFinder:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        queue = [(start, 0)]
        visited = set()
        paths = {start: []}
        while queue:
            node, distance = queue.pop(0)
            if node == end:
                return paths[node] + [node]
            if node not in visited:
                visited.add(node)
                for neighbor, weight in self.graph.nodes[node]:
                    if neighbor not in visited:
                        queue.append((neighbor, distance + weight))
                        paths[neighbor] = paths[node] + [node]
        return []

def main():
    g = Graph()
    g.add_node('A')
    g.add_node('B')
    g.add_node('C')
    g.add_node('D')
    g.add_node('E')
    g.add_node('F')
    g.add_node('G')
    g.add_edge('A', 'B', 1)
    g.add_edge('A', 'C', 4)
    g.add_edge('B', 'C', 2)
    g.add_edge('B', 'D', 5)
    g.add_edge('C', 'D', 1)
    g.add_edge('C', 'E', 3)
    g.add_edge('D', 'E', 1)
    g.add_edge('D', 'F', 8)
    g.add_edge('E', 'F', 2)
    g.add_edge('E', 'G', 2)
    g.add_edge('F', 'G', 7)
    pf = PathFinder(g)
    path = pf.find_shortest_path('A', 'G')
    print(path)
main()