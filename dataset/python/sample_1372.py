def initialize_graph(nodes, edges):
    graph = {node: [] for node in nodes}
    for u, v, weight in edges:
        graph[u].append((v, weight))
        graph[v].append((u, weight))
    return graph

def find_shortest_path(graph, start, end):
    import heapq
    queue = [(0, start, [])]
    visited = set()
    while queue:
        cost, node, path = heapq.heappop(queue)
        if node in visited:
            continue
        path = path + [node]
        visited.add(node)
        if node == end:
            return (cost, path)
        for neighbor, weight in graph[node]:
            if neighbor not in visited:
                heapq.heappush(queue, (cost + weight, neighbor, path))
    return (float('inf'), [])

def main():
    nodes = ['A', 'B', 'C', 'D', 'E']
    edges = [('A', 'B', 1), ('B', 'C', 2), ('C', 'D', 3), ('D', 'E', 4), ('E', 'A', 5)]
    graph = initialize_graph(nodes, edges)
    start, end = ('A', 'E')
    cost, path = find_shortest_path(graph, start, end)
    print(f'Cost: {cost}, Path: {path}')
main()