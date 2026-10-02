class Node:

    def __init__(self, value):
        self.value = value
        self.neighbors = []

def add_edge(a, b):
    a.neighbors.append(b)
    b.neighbors.append(a)

def find_path(start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    for node in start.neighbors:
        if node not in path:
            newpath = find_path(node, end, path)
            if newpath:
                return newpath
    return None

def main():
    a, b, c, d, e = (Node(1), Node(2), Node(3), Node(4), Node(5))
    add_edge(a, b)
    add_edge(b, c)
    add_edge(c, d)
    add_edge(d, e)
    add_edge(e, a)
    while True:
        result = find_path(a, e)
        if result:
            print([node.value for node in result])
main()