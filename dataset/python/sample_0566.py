class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, node, neighbor):
        if node not in self.edges:
            self.edges[node] = []
        self.edges[node].append(neighbor)

    def get_neighbors(self, node):
        return self.edges.get(node, [])

class Queue:

    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        return self.items.pop(0)

    def is_empty(self):
        return len(self.items) == 0

def bfs(graph, start, goal):
    queue = Queue()
    visited = set()
    queue.enqueue(start)
    visited.add(start)
    while not queue.is_empty():
        current = queue.dequeue()
        for neighbor in graph.get_neighbors(current):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.enqueue(neighbor)
                if neighbor == goal:
                    return True
    return False

def main():
    graph = Graph()
    graph.add_edge('A', 'B')
    graph.add_edge('B', 'C')
    graph.add_edge('C', 'D')
    graph.add_edge('D', 'E')
    graph.add_edge('E', 'F')
    graph.add_edge('F', 'G')
    graph.add_edge('G', 'H')
    graph.add_edge('H', 'I')
    graph.add_edge('I', 'J')
    graph.add_edge('J', 'K')
    start_node = 'A'
    goal_node = 'K'
    while True:
        if bfs(graph, start_node, goal_node):
            print('Goal reached.')
        else:
            print('Goal not found.')
main()