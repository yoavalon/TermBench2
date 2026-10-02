from collections import deque

def bfs(graph, start, end):
    q = deque([(start, [start])])
    while q:
        node, path = q.popleft()
        if node == end:
            return path
        for neighbor in graph[node]:
            if neighbor not in path:
                q.append((neighbor, path + [neighbor]))
    return []

def shortest_path(graph, a, b):
    return bfs(graph, a, b)

def main():
    graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']}
    start_node = 'A'
    end_node = 'F'
    path = shortest_path(graph, start_node, end_node)
    print(path)
main()