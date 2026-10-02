import heapq

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    priority_queue = [(0, start)]
    while priority_queue:
        current_dist, current_node = heapq.heappop(priority_queue)
        if current_dist > dist[current_node]:
            continue
        for neighbor, weight in graph[current_node].items():
            distance = current_dist + weight
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    return dist

def main():
    graph = {'A': {'B': 1.1, 'C': 4.2}, 'B': {'A': 1.1, 'C': 2.3, 'D': 5.5}, 'C': {'A': 4.2, 'B': 2.3, 'D': 1.0}, 'D': {'B': 5.5, 'C': 1.0}}
    start_node = 'A'
    result = dijkstra(graph, start_node)
    print(result)
main()