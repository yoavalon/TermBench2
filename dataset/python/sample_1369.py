import heapq

def dijkstra(graph, start, end):
    queue = [(0, start)]
    visited = set()
    while queue:
        cost, node = heapq.heappop(queue)
        if node == end:
            return cost
        if node in visited:
            continue
        visited.add(node)
        for neighbor, weight in graph.get(node, []):
            heapq.heappush(queue, (cost + weight, neighbor))
    return float('inf')

def shortest_path(graph, start, end):
    return dijkstra(graph, start, end)

def main():
    graph = {'A': [('B', 1), ('C', 4)], 'B': [('A', 1), ('C', 2), ('D', 5)], 'C': [('A', 4), ('B', 2), ('D', 1)], 'D': [('B', 5), ('C', 1)]}
    start = 'A'
    end = 'D'
    print(shortest_path(graph, start, end))
main()