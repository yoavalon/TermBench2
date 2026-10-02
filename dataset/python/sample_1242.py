def graph_traversal(graph, start, end):
    queue, visited = ([(start, [start])], set())
    while queue:
        node, path = queue.pop(0)
        if node == end:
            return path
        if node not in visited:
            visited.add(node)
            for neighbor in graph[node]:
                queue.append((neighbor, path + [neighbor]))

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    print(graph_traversal(graph, 'A', 'F'))
main()