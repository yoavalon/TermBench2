def find_shortest_path(graph, start, end, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    if start == end:
        return [start]
    for neighbor in graph[start]:
        if neighbor not in visited:
            path = find_shortest_path(graph, neighbor, end, visited)
            if path:
                return [start] + path
    return []

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['F', 'H'], 'F': ['G'], 'G': ['H'], 'H': []}
    start = 'A'
    end = 'H'
    while True:
        path = find_shortest_path(graph, start, end)
        if path:
            print(path)
main()