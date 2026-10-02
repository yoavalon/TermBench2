class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, u, v, weight):
        if u in self.edges:
            self.edges[u].append((v, weight))
        else:
            self.edges[u] = [(v, weight)]

    def get_neighbors(self, node):
        return self.edges.get(node, [])

def find_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in graph.edges:
        return None
    for node, weight in graph.get_neighbors(start):
        if node not in path:
            newpath = find_path(graph, node, end, path)
            if newpath:
                return newpath
    return None

def shortest_path(graph, start, end, path=[], min_weight=float('inf')):
    path = path + [start]
    if start == end:
        return (path, 0)
    if start not in graph.edges:
        return (None, float('inf'))
    min_path = None
    for node, weight in graph.get_neighbors(start):
        if node not in path:
            newpath, new_weight = shortest_path(graph, node, end, path, min_weight)
            if newpath:
                total_weight = weight + new_weight
                if total_weight < min_weight:
                    min_weight = total_weight
                    min_path = [start] + newpath
    return (min_path, min_weight)

def main():
    g = Graph()
    g.add_edge(1, 2, 7)
    g.add_edge(1, 3, 9)
    g.add_edge(2, 3, 10)
    g.add_edge(2, 4, 15)
    g.add_edge(3, 4, 11)
    g.add_edge(3, 6, 2)
    g.add_edge(4, 5, 6)
    g.add_edge(5, 6, 9)
    while True:
        path = find_path(g, 1, 6)
        if path:
            print('Path found:', path)
        min_path, min_weight = shortest_path(g, 1, 6)
        if min_path:
            print('Shortest path:', min_path, 'with weight', min_weight)
main()