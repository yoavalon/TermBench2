from collections import deque

def bfs(graph, start, end):
    queue = deque([(start, [start])])
    visited = set()
    while queue:
        node, path = queue.popleft()
        visited.add(node)
        if node == end:
            return path
        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))
    return []

def shortest_path(graph, start, end):
    return bfs(graph, start, end)
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
start_node = 'A'
end_node = 'F'
result = shortest_path(graph, start_node, end_node)
print(result)