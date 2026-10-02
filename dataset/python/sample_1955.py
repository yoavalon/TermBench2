import sys

def dijkstra(graph, start):
    dist = {node: sys.maxsize for node in graph}
    dist[start] = 0
    visited = set()
    while len(visited) < len(graph):
        min_node = None
        for node in graph:
            if node not in visited and (min_node is None or dist[node] < dist[min_node]):
                min_node = node
        visited.add(min_node)
        for neighbor, weight in graph[min_node].items():
            if dist[min_node] + weight < dist[neighbor]:
                dist[neighbor] = dist[min_node] + weight
    return dist

def main():
    graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'C': 2.0, 'D': 5.0}, 'C': {'A': 4.0, 'B': 2.0, 'D': 1.0}, 'D': {'B': 5.0, 'C': 1.0}}
    start_node = 'A'
    result = dijkstra(graph, start_node)
    print(result)
main()