class Graph:

    def __init__(self):
        self.nodes = {}

    def add_edge(self, u, v, weight=1):
        if u in self.nodes:
            self.nodes[u].append((v, weight))
        else:
            self.nodes[u] = [(v, weight)]
        if v not in self.nodes:
            self.nodes[v] = []

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph.nodes}
    distances[start] = 0
    unvisited = list(graph.nodes)
    while unvisited:
        current = min(unvisited, key=lambda node: distances[node])
        unvisited.remove(current)
        for neighbor, weight in graph.nodes[current]:
            distance = distances[current] + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
    return distances

def find_shortest_path(graph, start, end):
    distances = dijkstra(graph, start)
    path = []
    current = end
    while current != start:
        path.append(current)
        for neighbor, weight in graph.nodes[current]:
            if distances[current] == distances[neighbor] + weight:
                current = neighbor
                break
    path.append(start)
    return path[::-1]

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('C', 'D', 3)
    graph.add_edge('D', 'A', 4)
    start_node = 'A'
    end_node = 'D'
    shortest_path = find_shortest_path(graph, start_node, end_node)
    print('Shortest path:', shortest_path)
main()