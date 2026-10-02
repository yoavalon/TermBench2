class Graph:

    def __init__(self):
        self.adj_list = {}

    def add_vertex(self, vertex):
        if vertex not in self.adj_list:
            self.adj_list[vertex] = []

    def add_edge(self, vertex1, vertex2, weight):
        if vertex1 in self.adj_list and vertex2 in self.adj_list:
            self.adj_list[vertex1].append((vertex2, weight))
            self.adj_list[vertex2].append((vertex1, weight))

    def get_neighbors(self, vertex):
        return self.adj_list.get(vertex, [])

class PriorityQueue:

    def __init__(self):
        self.elements = []

    def empty(self):
        return len(self.elements) == 0

    def put(self, item, priority):
        self.elements.append((priority, item))
        self.elements.sort()

    def get(self):
        return self.elements.pop(0)[1]

def dijkstra(graph, start, end):
    queue = PriorityQueue()
    queue.put(start, 0)
    distances = {vertex: float('inf') for vertex in graph.adj_list}
    distances[start] = 0
    previous = {vertex: None for vertex in graph.adj_list}
    while not queue.empty():
        current = queue.get()
        if current == end:
            break
        for neighbor, weight in graph.get_neighbors(current):
            distance = distances[current] + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                previous[neighbor] = current
                queue.put(neighbor, distance)
    path = []
    while end is not None:
        path.append(end)
        end = previous[end]
    return (path[::-1], distances)

def main():
    graph = Graph()
    vertices = ['A', 'B', 'C', 'D', 'E']
    for vertex in vertices:
        graph.add_vertex(vertex)
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('C', 'D', 3)
    graph.add_edge('D', 'E', 4)
    graph.add_edge('E', 'A', 5)
    path, distances = dijkstra(graph, 'A', 'E')
    print('Path:', path)
    print('Distances:', distances)
if __name__ == '__main__':
    main()