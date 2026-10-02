def find_shortest_path(graph, start, end):
    queue = [(start, 0, {start})]
    while queue:
        node, cost, visited = queue.pop(0)
        if node == end:
            return cost
        for neighbor, weight in graph.get(node, {}).items():
            if neighbor not in visited:
                queue.append((neighbor, cost + weight, visited | {neighbor}))
    return -1
graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'D': 2.0}, 'C': {'A': 4.0, 'D': 1.0}, 'D': {'B': 2.0, 'C': 1.0}}
print(find_shortest_path(graph, 'A', 'D'))