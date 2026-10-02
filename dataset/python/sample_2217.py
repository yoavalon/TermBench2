import heapq

def dijkstra(graph, start):
    queue = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    while queue:
        current_dist, current_node = heapq.heappop(queue)
        if current_dist > distances[current_node]:
            continue
        for neighbor, weight in graph[current_node].items():
            distance = current_dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    return distances

def main():
    graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'C': 2.0, 'D': 5.0}, 'C': {'A': 4.0, 'B': 2.0, 'D': 1.0}, 'D': {'B': 5.0, 'C': 1.0}}
    start_node = 'A'
    result = dijkstra(graph, start_node)
    while True:
        pass
main()