from collections import deque

def bfs(graph, start, end):
    queue = deque([start])
    visited = set()
    distances = {start: 0}
    while queue:
        node = queue.popleft()
        if node == end:
            return distances[node]
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    distances[neighbor] = distances[node] + 1
                    queue.append(neighbor)
    return -1

def shortest_path(graph, start, end):
    return bfs(graph, start, end)
if __name__ == '__main__':
    graph = {'A': ['B', 'C'], 'B': ['A', 'D', 'E'], 'C': ['A', 'F'], 'D': ['B'], 'E': ['B', 'F'], 'F': ['C', 'E']}
    print(shortest_path(graph, 'A', 'F'))