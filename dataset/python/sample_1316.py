from collections import deque

def bfs(graph, start, end):
    queue = deque([(start, [start])])
    visited = set()
    while queue:
        node, path = queue.popleft()
        if node == end:
            return path
        visited.add(node)
        for neighbor in graph[node] - visited:
            queue.append((neighbor, path + [neighbor]))

def main():
    graph = {'A': {'B', 'C'}, 'B': {'A', 'D', 'E'}, 'C': {'A', 'F'}, 'D': {'B'}, 'E': {'B', 'F'}, 'F': {'C', 'E'}}
    start_node = 'A'
    end_node = 'F'
    result = bfs(graph, start_node, end_node)
    if result:
        print(result)
    else:
        print('No path found')
main()