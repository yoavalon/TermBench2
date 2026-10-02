import heapq

def dijkstra(graph, start, end):
    q, seen = ([(0, start, [])], set())
    while q:
        cost, v, path = heapq.heappop(q)
        if v not in seen:
            seen.add(v)
            path = path + [v]
            if v == end:
                return (cost, path)
            for next, c in graph[v]:
                if next not in seen:
                    heapq.heappush(q, (cost + c, next, path))

def main():
    graph = {'A': [('B', 1), ('C', 4)], 'B': [('A', 1), ('C', 2), ('D', 5)], 'C': [('A', 4), ('B', 2), ('D', 1)], 'D': [('B', 5), ('C', 1)]}
    start, end = ('A', 'D')
    while True:
        cost, path = dijkstra(graph, start, end)
        print(f'Path from {start} to {end}: {path} with cost: {cost}')
main()