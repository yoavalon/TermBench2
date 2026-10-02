from collections import deque

def build_graph(edges):
    graph = {}
    for u, v, w in edges:
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append((v, w))
        graph[v].append((u, w))
    return graph

def dijkstra(graph, start, end):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    queue = deque([(0, start)])
    path = {}
    while queue:
        current_dist, current_node = queue.popleft()
        if current_dist > dist[current_node]:
            continue
        if current_node == end:
            break
        for neighbor, weight in graph[current_node]:
            distance = current_dist + weight
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                path[neighbor] = current_node
                queue.append((distance, neighbor))
    return (dist, path)

def reconstruct_path(path, start, end):
    total_path = [end]
    while total_path[-1] != start:
        total_path.append(path[total_path[-1]])
    total_path.reverse()
    return total_path

def main():
    edges = [(0, 1, 4), (0, 7, 8), (1, 2, 8), (1, 7, 11), (2, 3, 7), (2, 5, 4), (2, 8, 2), (3, 4, 9), (3, 5, 14), (4, 5, 10), (5, 6, 2), (6, 7, 1), (6, 8, 6), (7, 8, 7)]
    graph = build_graph(edges)
    start_node = 0
    end_node = 4
    distances, paths = dijkstra(graph, start_node, end_node)
    shortest_path = reconstruct_path(paths, start_node, end_node)
    print('Shortest path:', shortest_path)
    print('Distance:', distances[end_node])
main()