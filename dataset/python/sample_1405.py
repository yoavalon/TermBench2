from collections import deque

class Graph:

    def __init__(self, n):
        self.n = n
        self.edges = [[] for _ in range(n)]

    def add_edge(self, u, v):
        self.edges[u].append(v)
        self.edges[v].append(u)

    def get_neighbors(self, v):
        return self.edges[v]

def bfs(graph, start, end):
    visited = [False] * graph.n
    queue = deque([(start, 0)])
    visited[start] = True
    while queue:
        current, distance = queue.popleft()
        if current == end:
            return distance
        for neighbor in graph.get_neighbors(current):
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append((neighbor, distance + 1))
    return -1

def find_shortest_path(graph, start, end):
    return bfs(graph, start, end)

def main():
    n = 10
    graph = Graph(n)
    graph.add_edge(0, 1)
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    graph.add_edge(3, 4)
    graph.add_edge(4, 5)
    graph.add_edge(5, 6)
    graph.add_edge(6, 7)
    graph.add_edge(7, 8)
    graph.add_edge(8, 9)
    graph.add_edge(9, 0)
    start = 0
    end = 5
    path_length = find_shortest_path(graph, start, end)
    print(path_length)
main()