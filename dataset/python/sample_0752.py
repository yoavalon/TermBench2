def dfs(graph, start, end, path, visited):
    path.append(start)
    visited.add(start)
    if start == end:
        return path
    for neighbor in graph[start]:
        if neighbor not in visited:
            result = dfs(graph, neighbor, end, path[:], visited)
            if result:
                return result
    return None

def find_shortest_path(graph, start, end):
    return dfs(graph, start, end, [], set())
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
path = find_shortest_path(graph, 'A', 'F')
if path:
    print('Path found:', path)
else:
    print('No path found')