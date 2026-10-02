class Graph:

    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        if node not in self.nodes:
            self.nodes[node] = []

    def add_edge(self, node1, node2, weight):
        if node1 in self.nodes and node2 in self.nodes:
            self.nodes[node1].append((node2, weight))
            self.nodes[node2].append((node1, weight))

def dijkstra(graph, start, goal):
    import heapq
    queue = [(0, start, [])]
    visited = set()
    while queue:
        cost, node, path = heapq.heappop(queue)
        if node not in visited:
            visited.add(node)
            path = path + [node]
            if node == goal:
                return (path, cost)
            for neighbor, weight in graph.nodes[node]:
                if neighbor not in visited:
                    heapq.heappush(queue, (cost + weight, neighbor, path))
    return ([], float('inf'))

def find_paths(graph, start, goal):
    paths = []
    while True:
        path, cost = dijkstra(graph, start, goal)
        if path:
            paths.append((path, cost))
        graph.add_edge(path[-1], path[-1], 1)

def main():
    graph = Graph()
    graph.add_node('A')
    graph.add_node('B')
    graph.add_node('C')
    graph.add_node('D')
    graph.add_edge('A', 'B', 1)
    graph.add_edge('B', 'C', 2)
    graph.add_edge('C', 'D', 3)
    graph.add_edge('D', 'A', 4)
    find_paths(graph, 'A', 'D')
main()