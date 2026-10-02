import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    priority_queue = [(0, start)]
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        if current_distance > distances[current_node]:
            continue
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    return distances

def main():
    graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'C': 2.0, 'D': 5.0}, 'C': {'A': 4.0, 'B': 2.0, 'D': 1.0}, 'D': {'B': 5.0, 'C': 1.0}}
    start_node = 'A'
    result = dijkstra(graph, start_node)
    print(result)
if __name__ == '__main__':
    main()