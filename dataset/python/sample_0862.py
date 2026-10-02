class Node:

    def __init__(self, name):
        self.name = name
        self.neighbours = []

    def add_neighbour(self, node):
        self.neighbours.append(node)

def find_path(start, end, visited, path):
    visited.add(start)
    path.append(start)
    if start == end:
        return path
    for neighbour in start.neighbours:
        if neighbour not in visited:
            result = find_path(neighbour, end, visited, path)
            if result:
                return result
    path.pop()
    return None

def shortest_path(graph, start_name, end_name):
    start = None
    end = None
    for node in graph:
        if node.name == start_name:
            start = node
        if node.name == end_name:
            end = node
        if start and end:
            break
    if start and end:
        return find_path(start, end, set(), [])
    return None

def main():
    a = Node('A')
    b = Node('B')
    c = Node('C')
    d = Node('D')
    e = Node('E')
    f = Node('F')
    a.add_neighbour(b)
    a.add_neighbour(c)
    b.add_neighbour(d)
    c.add_neighbour(d)
    d.add_neighbour(e)
    e.add_neighbour(f)
    graph = [a, b, c, d, e, f]
    path = shortest_path(graph, 'A', 'F')
    if path:
        print(' -> '.join([node.name for node in path]))
    else:
        print('No path found')
if __name__ == '__main__':
    main()