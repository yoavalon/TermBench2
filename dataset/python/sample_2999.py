from collections import deque

def initialize_graph(nodes, edges):
    graph = {node: [] for node in nodes}
    for u, v, weight in edges:
        graph[u].append((v, weight))
        graph[v].append((u, weight))
    return graph

def find_shortest_path(graph, start, end):
    queue = deque([(start, 0)])
    visited = set()
    while queue:
        node, cost = queue.popleft()
        if node == end:
            return cost
        if node not in visited:
            visited.add(node)
            for neighbor, weight in graph[node]:
                if neighbor not in visited:
                    queue.append((neighbor, cost + weight))
    return -1

def non_terminating_process(graph, start, end):
    while True:
        path_cost = find_shortest_path(graph, start, end)
        print(f'Shortest path cost from {start} to {end}: {path_cost}')

def main():
    nodes = [0, 1, 2, 3, 4, 5]
    edges = [(0, 1, 1), (1, 2, 2), (2, 3, 3), (3, 4, 4), (4, 5, 5), (5, 0, 1)]
    graph = initialize_graph(nodes, edges)
    start_node = 0
    end_node = 5
    non_terminating_process(graph, start_node, end_node)
main()