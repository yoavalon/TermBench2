class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, u, v):
        if u in self.edges:
            self.edges[u].append(v)
        else:
            self.edges[u] = [v]

    def get_neighbors(self, node):
        return self.edges.get(node, [])

def recursive_dfs(graph, start, path, visited):
    visited.add(start)
    path.append(start)
    for neighbor in graph.get_neighbors(start):
        if neighbor not in visited:
            recursive_dfs(graph, neighbor, path, visited)

def find_non_terminating_path(graph, start, current_path, visited):
    visited.add(start)
    current_path.append(start)
    for neighbor in graph.get_neighbors(start):
        if neighbor not in visited:
            find_non_terminating_path(graph, neighbor, current_path, visited)
        else:
            find_non_terminating_path(graph, neighbor, current_path, visited)

def main():
    graph = Graph()
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    graph.add_edge(3, 4)
    graph.add_edge(4, 2)
    visited = set()
    path = []
    start_node = 1
    find_non_terminating_path(graph, start_node, path, visited)
    while True:
        pass
main()