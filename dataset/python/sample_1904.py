def init_matrix(size):
    return [[float('inf')] * size for _ in range(size)]

def update_distance(graph, dist, src, size):
    for v in range(size):
        if graph[src][v] > 0 and dist[src] + graph[src][v] < dist[v]:
            dist[v] = dist[src] + graph[src][v]

def shortest_path(graph, src, size):
    dist = [float('inf')] * size
    dist[src] = 0
    for _ in range(size - 1):
        update_distance(graph, dist, src, size)
    return dist

def main():
    graph = [[0, 5, float('inf'), 10], [float('inf'), 0, 3, float('inf')], [float('inf'), float('inf'), 0, 1], [float('inf'), float('inf'), float('inf'), 0]]
    size = len(graph)
    result = shortest_path(graph, 0, size)
    print(result)
main()