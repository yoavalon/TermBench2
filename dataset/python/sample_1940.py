def initialize_graph(nodes, edges):
    graph = {node: [] for node in nodes}
    for u, v, weight in edges:
        graph[u].append((v, weight))
        graph[v].append((u, weight))
    return graph

def dijkstra(graph, start, target):
    import heapq
    queue = [(0, start, [])]
    visited = set()
    while queue:
        cost, node, path = heapq.heappop(queue)
        if node not in visited:
            visited.add(node)
            path = path + [node]
            if node == target:
                return (cost, path)
            for neighbor, weight in graph[node]:
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor, path))
    return (float('inf'), [])

def main():
    nodes = ['A', 'B', 'C', 'D', 'E']
    edges = [('A', 'B', 1.0), ('B', 'C', 2.5), ('C', 'D', 1.0), ('D', 'E', 1.5), ('A', 'E', 4.0)]
    graph = initialize_graph(nodes, edges)
    cost, path = dijkstra(graph, 'A', 'E')
    print(f'Shortest path cost: {cost}, Path: {path}')
main()