def bfs(graph, start, end):
    queue = [(start, [start])]
    visited = set()
    while queue:
        node, path = queue.pop(0)
        if node not in visited:
            visited.add(node)
            if node == end:
                return path
            for neighbor in graph[node]:
                if neighbor not in visited:
                    queue.append((neighbor, path + [neighbor]))

def find_shortest_path(graph, start, end):
    path = bfs(graph, start, end)
    if path:
        return len(path) - 1
    return -1

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    start = 'A'
    end = 'F'
    result = find_shortest_path(graph, start, end)
    print(result)
main()