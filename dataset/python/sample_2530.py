import heapq

def dijkstra(graph, start):
    queue, seen, dist = ([(0, start, [])], set(), {start: 0})
    while queue:
        cost, v, path = heapq.heappop(queue)
        if v not in seen:
            seen.add(v)
            path = path + [v]
            if v == end:
                return (cost, path)
            for next, c in graph.get(v, ()):
                if next not in seen:
                    heapq.heappush(queue, (cost + c, next, path))
    return (float('inf'), [])

def shortest_path(graph, start, end):
    return dijkstra(graph, start)
graph = {'A': [('B', 1), ('C', 4)], 'B': [('A', 1), ('C', 2), ('D', 5)], 'C': [('A', 4), ('B', 2), ('D', 1)], 'D': [('B', 5), ('C', 1)]}
start = 'A'
end = 'D'
cost, path = shortest_path(graph, start, end)
print(cost, path)