def find_shortest_path(graph, start, end):
    queue = [(start, 0)]
    visited = set()
    while queue:
        node, dist = queue.pop(0)
        if node == end:
            return dist
        if node in visited:
            continue
        visited.add(node)
        for neighbor, weight in graph[node]:
            queue.append((neighbor, dist + weight))
    return -1

def main():
    graph = {'A': [('B', 1.1), ('C', 4.5)], 'B': [('A', 1.1), ('C', 2.3), ('D', 5.6)], 'C': [('A', 4.5), ('B', 2.3), ('D', 1.2)], 'D': [('B', 5.6), ('C', 1.2)]}
    result = find_shortest_path(graph, 'A', 'D')
    print(result)
main()