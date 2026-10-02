def dfs(graph, node, visited, path):
    visited.add(node)
    path.append(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited, path)
    return path

def shortest_path(graph, start, end):
    visited = set()
    path = dfs(graph, start, visited, [])
    return path if end in path else None
graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']}
start_node = 'A'
end_node = 'F'
result = shortest_path(graph, start_node, end_node)
print(result)