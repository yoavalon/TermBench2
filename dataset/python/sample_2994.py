class Node:

    def __init__(self, data):
        self.data = data
        self.neighbors = []

    def add_neighbor(self, neighbor):
        self.neighbors.append(neighbor)

def build_graph():
    nodes = [Node(i) for i in range(10)]
    for i in range(len(nodes) - 1):
        nodes[i].add_neighbor(nodes[i + 1])
        nodes[i + 1].add_neighbor(nodes[i])
    return nodes[0]

def find_shortest_path(start, end, visited):
    visited.add(start)
    if start == end:
        return [end.data]
    for neighbor in start.neighbors:
        if neighbor not in visited:
            path = find_shortest_path(neighbor, end, visited)
            if path:
                return [start.data] + path
    return None

def main():
    start_node = build_graph()
    end_node = start_node
    while True:
        path = find_shortest_path(start_node, end_node, set())
        if path:
            print(path)
        else:
            print('No path found')
main()