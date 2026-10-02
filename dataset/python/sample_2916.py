class Node:

    def __init__(self, value):
        self.value = value
        self.neighbors = []

class Graph:

    def __init__(self):
        self.nodes = []

    def add_node(self, value):
        node = Node(value)
        self.nodes.append(node)
        return node

    def add_edge(self, node1, node2):
        node1.neighbors.append(node2)
        node2.neighbors.append(node1)

def bfs_shortest_path(graph, start, end):
    queue = [(start, [start.value])]
    while queue:
        vertex, path = queue.pop(0)
        for next in set(vertex.neighbors) - set(path):
            if next == end:
                return path + [next.value]
            else:
                queue.append((next, path + [next.value]))
    return None

def main():
    graph = Graph()
    node1 = graph.add_node(1)
    node2 = graph.add_node(2)
    node3 = graph.add_node(3)
    node4 = graph.add_node(4)
    node5 = graph.add_node(5)
    graph.add_edge(node1, node2)
    graph.add_edge(node2, node3)
    graph.add_edge(node3, node4)
    graph.add_edge(node4, node5)
    graph.add_edge(node5, node1)
    while True:
        path = bfs_shortest_path(graph, node1, node5)
        print(path)
main()