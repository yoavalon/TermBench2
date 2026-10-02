def bfs(graph, start, end, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    if start == end:
        return [start]
    for neighbor in graph[start]:
        if neighbor not in visited:
            path = bfs(graph, neighbor, end, visited)
            if path:
                return [start] + path
    return []
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
bfs(graph, 'A', 'F')