import heapq

def dijkstra(graph, start, end):
    queue = [(0, start, [])]
    visited = set()
    while queue:
        cost, node, path = heapq.heappop(queue)
        if node not in visited:
            visited.add(node)
            path = path + [node]
            if node == end:
                return (cost, path)
            for neighbor, weight in graph.get(node, []):
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor, path))
    return (float('inf'), [])

def main():
    graph = {'A': [('B', 1.5), ('C', 2.3)], 'B': [('C', 0.9), ('D', 3.2)], 'C': [('D', 1.7)], 'D': []}
    start = 'A'
    end = 'D'
    result = dijkstra(graph, start, end)
    print(result)
main()