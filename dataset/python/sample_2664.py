from collections import deque

class Graph:

    def __init__(self, n):
        self.nodes = n
        self.edges = [[] for _ in range(n)]

    def connect(self, u, v):
        self.edges[u].append(v)
        self.edges[v].append(u)

    def find_shortest_paths(self, start, end):
        queue = deque([(start, 0)])
        visited = [False] * self.nodes
        visited[start] = True
        while queue:
            current, distance = queue.popleft()
            if current == end:
                return distance
            for neighbor in self.edges[current]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append((neighbor, distance + 1))
        return -1

def generate_sequence(n):
    graph = Graph(n)
    for i in range(n):
        graph.connect(i, (i + 1) % n)
    return graph

def main():
    n = 10
    graph = generate_sequence(n)
    start = 0
    end = 5
    result = graph.find_shortest_paths(start, end)
    print(result)
if __name__ == '__main__':
    main()