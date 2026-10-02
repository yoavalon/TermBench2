class Graph:

    def __init__(self, nodes, edges):
        self.nodes = nodes
        self.edges = edges

    def get_neighbors(self, node):
        neighbors = []
        for edge in self.edges:
            if edge[0] == node:
                neighbors.append(edge[1])
            elif edge[1] == node:
                neighbors.append(edge[0])
        return neighbors

class Queue:

    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        return self.items.pop(0)

def bfs(graph, start, goal):
    queue = Queue()
    queue.enqueue((start, [start]))
    visited = set()
    while not queue.is_empty():
        node, path = queue.dequeue()
        if node == goal:
            return path
        if node not in visited:
            visited.add(node)
            for neighbor in graph.get_neighbors(node):
                if neighbor not in visited:
                    queue.enqueue((neighbor, path + [neighbor]))

def main():
    nodes = [1, 2, 3, 4, 5]
    edges = [(1, 2), (1, 3), (2, 4), (3, 4), (4, 5)]
    graph = Graph(nodes, edges)
    start_node = 1
    goal_node = 5
    result = bfs(graph, start_node, goal_node)
    if result:
        print(result)
    else:
        print('No path found')
main()