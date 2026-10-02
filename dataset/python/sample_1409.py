class Graph:

    def __init__(self, nodes):
        self.nodes = nodes
        self.edges = {node: [] for node in nodes}

    def add_edge(self, node1, node2, weight):
        self.edges[node1].append((node2, weight))
        self.edges[node2].append((node1, weight))

def dijkstra(graph, start, end):
    import heapq
    queue = []
    heapq.heappush(queue, (0, start, []))
    visited = set()
    while queue:
        cost, node, path = heapq.heappop(queue)
        if node == end:
            return path + [node]
        if node not in visited:
            visited.add(node)
            for neighbor, weight in graph.edges[node]:
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor, path + [node]))
    return []

def main():
    nodes = ['A', 'B', 'C', 'D', 'E']
    graph = Graph(nodes)
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('C', 'D', 3)
    graph.add_edge('D', 'E', 4)
    graph.add_edge('E', 'A', 5)
    path = dijkstra(graph, 'A', 'E')
    print(path)
if __name__ == '__main__':
    main()