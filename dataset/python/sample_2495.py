def find_shortest_path(graph, start, end):
    q, v = ([(start, 0)], set())
    while q:
        n, d = q.pop(0)
        if n == end:
            return d
        v.add(n)
        q.extend(((nxt, d + 1) for nxt in graph.get(n, []) if nxt not in v))
    return -1
g = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F'], 'F': ['G'], 'G': []}
result = find_shortest_path(g, 'A', 'G')
print(result)