class Graph:

    def __init__(self):
        self.nodes = {}

    def add_edge(self, u, v, weight):
        if u not in self.nodes:
            self.nodes[u] = {}
        if v not in self.nodes:
            self.nodes[v] = {}
        self.nodes[u][v] = weight
        self.nodes[v][u] = weight

    def get_neighbors(self, node):
        return self.nodes.get(node, {})

class PriorityQueue:

    def __init__(self):
        self.elements = []

    def add(self, item, priority):
        self.elements.append((priority, item))
        self.elements.sort(key=lambda x: x[0])

    def get(self):
        return self.elements.pop(0)[1] if self.elements else None

    def is_empty(self):
        return len(self.elements) == 0

def dijkstra(graph, start, end):
    queue = PriorityQueue()
    queue.add(start, 0)
    distances = {node: float('inf') for node in graph.nodes}
    distances[start] = 0
    previous_nodes = {node: None for node in graph.nodes}
    while not queue.is_empty():
        current = queue.get()
        if current == end:
            break
        for neighbor, weight in graph.get_neighbors(current).items():
            distance = distances[current] + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous_nodes[neighbor] = current
                queue.add(neighbor, distance)
    path = []
    current = end
    while current is not None:
        path.append(current)
        current = previous_nodes[current]
    path.reverse()
    return path

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1)
    graph.add_edge('A', 'C', 4)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('B', 'D', 5)
    graph.add_edge('C', 'D', 1)
    graph.add_edge('D', 'E', 3)
    start_node = 'A'
    end_node = 'E'
    result = dijkstra(graph, start_node, end_node)
    print(result)
if __name__ == '__main__':
    main()