def dfs(graph, node, visited, path, paths):
    visited.add(node)
    path.append(node)
    if len(graph[node]) == 0:
        paths.append(path.copy())
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited, path, paths)
    path.pop()
    visited.remove(node)

def shortest_path(graph, start, end):
    paths = []
    dfs(graph, start, set(), [], paths)
    min_length = float('inf')
    best_path = None
    for path in paths:
        if path[-1] == end and len(path) < min_length:
            min_length = len(path)
            best_path = path
    return best_path
graph = {'A': ['B', 'C'], 'B': ['D'], 'C': ['D'], 'D': []}
start_node = 'A'
end_node = 'D'
print(shortest_path(graph, start_node, end_node))