def bfs(graph, start, end):
    queue = [(start, [start])]
    while queue:
        node, path = queue.pop(0)
        for neighbor in graph[node]:
            if neighbor == end:
                return path + [neighbor]
            elif neighbor not in path:
                queue.append((neighbor, path + [neighbor]))
    return None

def find_shortest_path(graph, start, end):
    return bfs(graph, start, end)

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    start = 'A'
    end = 'F'
    path = find_shortest_path(graph, start, end)
    if path:
        print(' -> '.join(path))
    else:
        print('No path found')
main()