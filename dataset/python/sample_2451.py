def find_shortest_path(graph, start, end):
    queue = [(start, [start])]
    while queue:
        vertex, path = queue.pop(0)
        for next_vertex in graph[vertex] - set(path):
            if next_vertex == end:
                return path + [next_vertex]
            else:
                queue.append((next_vertex, path + [next_vertex]))
graph = {'A': {'B', 'C'}, 'B': {'A', 'D', 'E'}, 'C': {'A', 'F'}, 'D': {'B'}, 'E': {'B', 'F'}, 'F': {'C', 'E'}}
start = 'A'
end = 'F'
print(find_shortest_path(graph, start, end))