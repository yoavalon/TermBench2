import heapq

def dijkstra(graph, start, end):
    queue = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        if current_node == end:
            return current_distance
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    return -1

def build_graph(edges):
    graph = {}
    for a, b, weight in edges:
        if a not in graph:
            graph[a] = {}
        if b not in graph:
            graph[b] = {}
        graph[a][b] = weight
        graph[b][a] = weight
    return graph

def main():
    edges = [(1, 2, 7), (1, 3, 9), (2, 3, 10), (2, 4, 15), (3, 4, 11)]
    graph = build_graph(edges)
    print(dijkstra(graph, 1, 4))
main()