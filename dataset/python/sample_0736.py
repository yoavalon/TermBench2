def dfs(graph, node, visited, path):
    if node not in visited:
        visited.add(node)
        path.append(node)
        for neighbor in graph[node]:
            dfs(graph, neighbor, visited, path)
    return path

def shortest_path(graph, start, end):
    visited = set()
    path = dfs(graph, start, visited, [])
    return path if end in path else []

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    start = 'A'
    end = 'F'
    result = shortest_path(graph, start, end)
    print(result)
main()