def dijkstra(graph, start, end):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    unvisited = set(graph)
    current = start
    while current != end and unvisited:
        for neighbor, weight in graph[current].items():
            distance = distances[current] + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
        unvisited.remove(current)
        if not unvisited:
            break
        current = min(unvisited, key=distances.get)
        if current not in unvisited:
            break
    return distances[end]

def main():
    graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'C': 2.0, 'D': 5.0}, 'C': {'A': 4.0, 'B': 2.0, 'D': 1.0}, 'D': {'B': 5.0, 'C': 1.0}}
    start = 'A'
    end = 'D'
    print(dijkstra(graph, start, end))
main()