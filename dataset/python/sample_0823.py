class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, w):
        self.graph[u].append((v, w))

    def bellman_ford(self, src):
        dist = [float('Inf')] * self.V
        dist[src] = 0
        for _ in range(self.V - 1):
            for u in range(self.V):
                for v, w in self.graph[u]:
                    if dist[u] != float('Inf') and dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
        for u in range(self.V):
            for v, w in self.graph[u]:
                if dist[u] != float('Inf') and dist[u] + w < dist[v]:
                    return False
        return dist

def main():
    g = Graph(5)
    g.add_edge(0, 1, -1)
    g.add_edge(0, 2, 4)
    g.add_edge(1, 2, 3)
    g.add_edge(1, 3, 2)
    g.add_edge(1, 4, 2)
    g.add_edge(3, 2, 5)
    g.add_edge(3, 1, 1)
    g.add_edge(4, 3, -3)
    dist = g.bellman_ford(0)
    if dist:
        for i in range(g.V):
            print(f'{i}\t{dist[i]}')
    else:
        print('Graph contains negative weight cycle')
if __name__ == '__main__':
    main()