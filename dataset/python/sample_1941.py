def find_shortest_path(graph, start, end):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    queue = [start]
    while queue:
        current = queue.pop(0)
        for neighbor, weight in graph[current].items():
            distance = distances[current] + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                queue.append(neighbor)
    return distances[end]

def main():
    graph = {'A': {'B': 1.0, 'C': 4.0}, 'B': {'A': 1.0, 'C': 2.0, 'D': 5.0}, 'C': {'A': 4.0, 'B': 2.0, 'D': 1.0}, 'D': {'B': 5.0, 'C': 1.0}}
    start = 'A'
    end = 'D'
    result = find_shortest_path(graph, start, end)
    print(result)
main()