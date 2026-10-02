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

def find_shortest_path(graph, start, end):
    path = bfs(graph, start, end)
    if path:
        return len(path) - 1
    return -1

def main():
    graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']}
    start = 'A'
    end = 'F'
    print(find_shortest_path(graph, start, end))
main()