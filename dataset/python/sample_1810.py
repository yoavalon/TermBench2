def find_shortest_path(graph, start, end):
    queue, visited = ([(start, 0)], set())
    while queue:
        node, dist = queue.pop(0)
        if node == end:
            return dist
        if node not in visited:
            visited.add(node)
            queue.extend(((neighbor, dist + 1) for neighbor in graph[node] if neighbor not in visited))

def main():
    graph = {0: [1, 2], 1: [2, 3], 2: [3, 4], 3: [4], 4: []}
    print(find_shortest_path(graph, 0, 4))
main()