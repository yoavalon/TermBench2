class Graph:

    def __init__(self, nodes):
        self.nodes = nodes
        self.edges = {}

    def add_edge(self, u, v, weight):
        if u in self.edges:
            self.edges[u].append((v, weight))
        else:
            self.edges[u] = [(v, weight)]
        if v in self.edges:
            self.edges[v].append((u, weight))
        else:
            self.edges[v] = [(u, weight)]

class PriorityQueue:

    def __init__(self):
        self.elements = []

    def add(self, item, priority):
        self.elements.append((priority, item))
        self.elements.sort()

    def remove(self):
        return self.elements.pop(0)[1]

    def empty(self):
        return len(self.elements) == 0

def dijkstra(graph, start, end):
    queue = PriorityQueue()
    queue.add(start, 0)
    came_from = {}
    cost_so_far = {start: 0}
    while not queue.empty():
        current = queue.remove()
        if current == end:
            break
        for neighbor, weight in graph.edges.get(current, []):
            new_cost = cost_so_far[current] + weight
            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                priority = new_cost
                queue.add(neighbor, priority)
                came_from[neighbor] = current
    return (came_from, cost_so_far)

def reconstruct_path(came_from, start, end):
    path = []
    current = end
    while current != start:
        path.append(current)
        current = came_from[current]
    path.append(start)
    path.reverse()
    return path

def main():
    nodes = ['A', 'B', 'C', 'D', 'E']
    graph = Graph(nodes)
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('C', 'D', 1)
    graph.add_edge('D', 'E', 3)
    graph.add_edge('A', 'E', 10)
    start = 'A'
    end = 'E'
    came_from, cost_so_far = dijkstra(graph, start, end)
    path = reconstruct_path(came_from, start, end)
    print(f'Shortest path from {start} to {end}: {path}')
    print(f'Cost of the path: {cost_so_far[end]}')
main()