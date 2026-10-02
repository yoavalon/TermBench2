def dfs(graph, node, visited, path):
    visited.add(node)
    path.append(node)
    if len(path) == len(graph):
        return path
    for neighbor in graph[node]:
        if neighbor not in visited:
            result = dfs(graph, neighbor, visited, path[:])
            if result:
                return result
    return None

def shortest_path(graph, start):
    visited = set()
    path = dfs(graph, start, visited, [])
    return path if path else []
graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']}
start = 'A'
print(shortest_path(graph, start))