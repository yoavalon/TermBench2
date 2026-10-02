from collections import deque

def bfs_shortest_path(graph, start, goal):
    queue = deque([(start, [start])])
    visited = set()
    while queue:
        node, path = queue.popleft()
        if node == goal:
            return path
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F'], 'F': ['G'], 'G': []}
    start_node = 'A'
    goal_node = 'G'
    result = bfs_shortest_path(graph, start_node, goal_node)
    print(result)
main()