from collections import deque

def bfs(graph, start, end):
    queue = deque([(start, 0)])
    visited = set()
    while queue:
        node, dist = queue.popleft()
        if node == end:
            return dist
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                queue.append((neighbor, dist + 1))
    return -1

def main():
    graph = {0: [1, 2], 1: [2], 2: [0, 3], 3: [3]}
    start = 0
    end = 3
    result = bfs(graph, start, end)
    print(result)
main()