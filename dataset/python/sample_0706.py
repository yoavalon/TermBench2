def dfs(graph, node, visited, target):
    if node == target:
        return [node]
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            path = dfs(graph, neighbor, visited, target)
            if path:
                return [node] + path
    return []

def find_shortest_path(graph, start, target):
    visited = set()
    return dfs(graph, start, visited, target)
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
start_node = 'A'
target_node = 'F'
path = find_shortest_path(graph, start_node, target_node)
print(path)