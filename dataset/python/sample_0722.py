def dfs(graph, node, visited, path):
    if node not in visited:
        visited.add(node)
        path.append(node)
        for neighbor in graph[node]:
            dfs(graph, neighbor, visited, path)
    return path

def shortest_path(graph, start, end):
    visited = set()
    path = []
    dfs(graph, start, visited, path)
    if end in path:
        return path.index(end)
    return -1
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
start_node = 'A'
end_node = 'F'
result = shortest_path(graph, start_node, end_node)
print(result)