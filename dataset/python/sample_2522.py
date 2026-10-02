def bfs(graph, start, goal):
    queue = [(start, [start])]
    while queue:
        vertex, path = queue.pop(0)
        for next in set(graph[vertex]) - set(path):
            if next == goal:
                return path + [next]
            else:
                queue.append((next, path + [next]))
    return None

def find_path(graph, start, goal):
    path = bfs(graph, start, goal)
    return path if path else []

def main():
    graph = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': [], 'E': ['F'], 'F': []}
    start_node = 'A'
    goal_node = 'F'
    result = find_path(graph, start_node, goal_node)
    print(result)
main()