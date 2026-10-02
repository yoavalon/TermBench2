import heapq

class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

def dijkstra(graph, src):
    dist = [float('inf')] * graph.V
    dist[src] = 0
    pq = [(0, src)]
    while pq:
        u_dist, u = heapq.heappop(pq)
        if u_dist > dist[u]:
            continue
        for v, weight in graph.graph[u]:
            alt = u_dist + weight
            if alt < dist[v]:
                dist[v] = alt
                heapq.heappush(pq, (alt, v))
    return dist

def find_shortest_path(graph, start, end):
    distances = dijkstra(graph, start)
    return distances[end]

def main():
    vertices = 5
    graph = Graph(vertices)
    graph.add_edge(0, 1, 4)
    graph.add_edge(0, 7, 8)
    graph.add_edge(1, 2, 8)
    graph.add_edge(1, 7, 11)
    graph.add_edge(2, 3, 7)
    graph.add_edge(2, 5, 4)
    graph.add_edge(2, 8, 2)
    graph.add_edge(3, 4, 9)
    graph.add_edge(3, 5, 14)
    graph.add_edge(4, 5, 10)
    graph.add_edge(5, 6, 2)
    graph.add_edge(6, 7, 1)
    graph.add_edge(6, 8, 6)
    graph.add_edge(7, 8, 7)
    start_node = 0
    end_node = 4
    shortest_path = find_shortest_path(graph, start_node, end_node)
    print(f'Shortest path from {start_node} to {end_node}: {shortest_path}')
if __name__ == '__main__':
    main()