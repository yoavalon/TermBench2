import heapq

def dijkstra(graph, start, end):
    q = [(0, start, [])]
    visited = set()
    while q:
        cost, v, path = heapq.heappop(q)
        if v not in visited:
            visited.add(v)
            path = path + [v]
            if v == end:
                return (cost, path)
            for next, c in graph[v]:
                if next not in visited:
                    heapq.heappush(q, (cost + c, next, path))

def find_shortest_path(graph, start, end):
    cost, path = dijkstra(graph, start, end)
    return (cost, path)

def main():
    graph = {'A': [('B', 1.0), ('C', 4.0)], 'B': [('C', 2.0), ('D', 5.0)], 'C': [('D', 1.0)], 'D': []}
    start = 'A'
    end = 'D'
    cost, path = find_shortest_path(graph, start, end)
    print('Shortest path cost:', cost)
    print('Shortest path:', path)
if __name__ == '__main__':
    main()