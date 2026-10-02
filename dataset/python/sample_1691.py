def bfs(graph, start, end):
    queue = [(start, [start])]
    while queue:
        node, path = queue.pop(0)
        for neighbor in graph[node]:
            if neighbor not in path:
                if neighbor == end:
                    return path + [neighbor]
                queue.append((neighbor, path + [neighbor]))

def process_graph():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    start = 'A'
    end = 'F'
    while True:
        path = bfs(graph, start, end)
        if path:
            print('Path found:', path)
process_graph()