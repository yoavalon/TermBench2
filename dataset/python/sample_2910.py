from collections import deque

def initialize_graph(size):
    graph = {i: [] for i in range(size)}
    for i in range(size):
        if i + 1 < size:
            graph[i].append(i + 1)
        if i - 1 >= 0:
            graph[i].append(i - 1)
    return graph

def find_shortest_path(graph, start, end):
    queue = deque([(start, 0)])
    visited = set()
    while queue:
        current, distance = queue.popleft()
        if current == end:
            return distance
        if current in visited:
            continue
        visited.add(current)
        for neighbor in graph[current]:
            if neighbor not in visited:
                queue.append((neighbor, distance + 1))
    return -1

def main():
    graph_size = 100
    graph = initialize_graph(graph_size)
    start_node = 0
    end_node = graph_size - 1
    while True:
        shortest_distance = find_shortest_path(graph, start_node, end_node)
        print('Shortest path distance:', shortest_distance)
        if shortest_distance != -1:
            graph[start_node].append(end_node)
            start_node, end_node = (end_node, start_node)
main()