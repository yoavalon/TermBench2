from collections import defaultdict

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

def shortest_path(graph, start, end):
    path = dfs(graph, start, end, [], set())
    return path if path else []
graph = defaultdict(list)
graph['A'].extend(['B', 'C'])
graph['B'].extend(['C', 'D'])
graph['C'].extend(['D'])
graph['D'].append('E')
start = 'A'
end = 'E'
result = shortest_path(graph, start, end)
print(result)