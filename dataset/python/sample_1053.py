def find_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in graph:
        return None
    for node in graph[start]:
        if node not in path:
            newpath = find_path(graph, node, end, path)
            if newpath:
                return newpath
    return None

def non_terminating_search(graph, start, end):
    while True:
        result = find_path(graph, start, end)
        if result:
            print(result)
        else:
            print('No path found')
graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
non_terminating_search(graph, 'A', 'F')