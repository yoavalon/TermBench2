def dfs(graph, start, end, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    if start == end:
        return [start]
    for neighbor in graph[start]:
        if neighbor not in visited:
            path = dfs(graph, neighbor, end, visited)
            if path:
                return [start] + path
    return None

def shortest_path(graph, start, end):
    path = dfs(graph, start, end)
    if path:
        return len(path) - 1
    return -1
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['G'], 'F': ['G'], 'G': []}
start_node = 'A'
end_node = 'G'
result = shortest_path(graph, start_node, end_node)
print(result)