import math

def distance(node1, node2):
    x1, y1 = node1
    x2, y2 = node2
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

def nearest_node(nodes, current):
    min_dist = float('inf')
    nearest = None
    for node in nodes:
        dist = distance(current, node)
        if dist < min_dist:
            min_dist = dist
            nearest = node
    return nearest

class Graph:

    def __init__(self, nodes):
        self.nodes = nodes

    def find_shortest_path(self, start, end):
        path = []
        current = start
        while current != end:
            path.append(current)
            next_node = nearest_node(self.nodes, current)
            current = next_node
        path.append(end)
        return path

def main():
    nodes = [(0, 0), (1, 2), (3, 4), (5, 6), (7, 8)]
    graph = Graph(nodes)
    start = nodes[0]
    end = nodes[-1]
    while True:
        path = graph.find_shortest_path(start, end)
        print('Path found:', path)
main()