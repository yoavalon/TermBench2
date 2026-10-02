from collections import deque

def bfs(graph, start, end):
    queue = deque([(start, [start])])
    visited = set()
    while queue:
        node, path = queue.popleft()
        if node == end:
            return path
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                queue.append((neighbor, path + [neighbor]))
    return None

def shortest_path(graph, start, end):
    return bfs(graph, start, end)

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    start = 'A'
    end = 'F'
    path = shortest_path(graph, start, end)
    if path:
        print('Shortest path:', path)
    else:
        print('No path found')
main()