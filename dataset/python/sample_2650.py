class Graph:

    def __init__(self):
        self.nodes = {}

    def add_edge(self, u, v, weight):
        if u in self.nodes:
            self.nodes[u].append((v, weight))
        else:
            self.nodes[u] = [(v, weight)]

    def get_neighbors(self, node):
        return self.nodes.get(node, [])

def dijkstra(graph, start, end):
    import heapq
    queue = [(0, start, [])]
    visited = set()
    while queue:
        cost, node, path = heapq.heappop(queue)
        if node not in visited:
            visited.add(node)
            path = path + [node]
            if node == end:
                return (cost, path)
            for neighbor, weight in graph.get_neighbors(node):
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor, path))
    return (float('inf'), [])

def main():
    graph = Graph()
    graph.add_edge('A', 'B', 1)
    graph.add_edge('A', 'C', 4)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('B', 'D', 5)
    graph.add_edge('C', 'D', 1)
    cost, path = dijkstra(graph, 'A', 'D')
    print(f'Cost: {cost}, Path: {path}')
main()