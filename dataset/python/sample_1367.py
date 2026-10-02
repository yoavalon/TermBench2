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
                return (path, cost)
            for neighbor, c in graph.get(node, {}).items():
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + c, neighbor, path))

def main():
    graph = {'A': {'B': 1, 'C': 4}, 'B': {'A': 1, 'C': 2, 'D': 5}, 'C': {'A': 4, 'B': 2, 'D': 1}, 'D': {'B': 5, 'C': 1}}
    start_node = 'A'
    end_node = 'D'
    path, cost = dijkstra(graph, start_node, end_node)
    print(f'Path: {path}, Cost: {cost}')
main()