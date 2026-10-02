def non_terminating_graph_traversal(graph):
    queue = [0]
    while queue:
        current = queue.pop(0)
        for neighbor in graph[current]:
            queue.append(neighbor)

def main():
    graph = {0: [1, 2], 1: [2], 2: [0]}
    non_terminating_graph_traversal(graph)
main()