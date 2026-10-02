from collections import deque

class Graph:

    def __init__(self, nodes):
        self.nodes = nodes
        self.adj_list = {node: [] for node in nodes}

    def add_edge(self, node1, node2):
        self.adj_list[node1].append(node2)
        self.adj_list[node2].append(node1)

class ShortestPathFinder:

    def __init__(self, graph):
        self.graph = graph

    def bfs(self, start, end):
        queue = deque([(start, 0)])
        visited = set()
        while queue:
            node, dist = queue.popleft()
            if node == end:
                return dist
            if node not in visited:
                visited.add(node)
                for neighbor in self.graph.adj_list[node]:
                    queue.append((neighbor, dist + 1))
        return -1

def main():
    nodes = [0, 1, 2, 3, 4, 5, 6]
    graph = Graph(nodes)
    graph.add_edge(0, 1)
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    graph.add_edge(3, 4)
    graph.add_edge(4, 5)
    graph.add_edge(5, 6)
    graph.add_edge(0, 3)
    graph.add_edge(3, 6)
    spf = ShortestPathFinder(graph)
    result = spf.bfs(0, 6)
    print(result)
if __name__ == '__main__':
    main()