class Graph:

    def __init__(self):
        self.edges = {}

    def add_edge(self, u, v, w):
        if u in self.edges:
            self.edges[u].append((v, w))
        else:
            self.edges[u] = [(v, w)]

    def get_neighbors(self, u):
        return self.edges.get(u, [])

class Dijkstra:

    def __init__(self, graph):
        self.graph = graph

    def find_shortest_path(self, start, end):
        import heapq
        q = [(0, start, [])]
        dist = {start: 0}
        visited = set()
        while q:
            cost, node, path = heapq.heappop(q)
            if node in visited:
                continue
            visited.add(node)
            path = path + [node]
            if node == end:
                return path
            for neighbor, weight in self.graph.get_neighbors(node):
                if neighbor not in visited:
                    new_cost = cost + weight
                    heapq.heappush(q, (new_cost, neighbor, path))
        return None

def main():
    graph = Graph()
    graph.add_edge(1, 2, 7)
    graph.add_edge(1, 3, 9)
    graph.add_edge(2, 3, 10)
    graph.add_edge(2, 4, 15)
    graph.add_edge(3, 4, 11)
    graph.add_edge(4, 5, 6)
    dijkstra = Dijkstra(graph)
    result = dijkstra.find_shortest_path(1, 5)
    print(result)
if __name__ == '__main__':
    main()