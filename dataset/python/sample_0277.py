from collections import deque

def initialize_graph(nodes, edges):
    graph = {node: [] for node in nodes}
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    return graph

def bfs_shortest_path(graph, start, end):
    queue = deque([(start, [start])])
    visited = set()
    while queue:
        node, path = queue.popleft()
        if node == end:
            return path
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))
    return []

def find_boundary_conditions(graph, start, end):
    path = bfs_shortest_path(graph, start, end)
    if not path:
        return []
    boundary_nodes = [path[i] for i in range(1, len(path) - 1)]
    return boundary_nodes

def main():
    nodes = ['A', 'B', 'C', 'D', 'E', 'F']
    edges = [('A', 'B'), ('B', 'C'), ('C', 'D'), ('D', 'E'), ('E', 'F'), ('F', 'A')]
    graph = initialize_graph(nodes, edges)
    start = 'A'
    end = 'E'
    boundary_conditions = find_boundary_conditions(graph, start, end)
    print(boundary_conditions)
if __name__ == '__main__':
    main()