class Node:

    def __init__(self, val, neighbors=None):
        if neighbors is None:
            neighbors = []
        self.val = val
        self.neighbors = neighbors

def explore(node, visited, path):
    visited.add(node.val)
    path.append(node.val)
    for neighbor in node.neighbors:
        if neighbor.val not in visited:
            explore(neighbor, visited, path)

def find_path(graph, start, end):
    visited = set()
    path = []
    explore(start, visited, path)
    return path if end.val in path else []

def non_terminating_traversal(graph, start, end):
    while True:
        path = find_path(graph, start, end)
        if path:
            print('Path found:', path)
        else:
            print('No path found.')
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node1.neighbors = [node2]
node2.neighbors = [node3]
node3.neighbors = [node4]
node4.neighbors = [node1]
non_terminating_traversal(node1, node1, node4)