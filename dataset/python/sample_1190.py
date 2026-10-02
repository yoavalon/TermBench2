class SupplyChain:

    def __init__(self, nodes, edges):
        self.nodes = nodes
        self.edges = edges

    def optimize(self, start, end):
        path = self.find_path(start, end, [])
        if path:
            return self.calculate_cost(path)
        return float('inf')

    def find_path(self, current, end, visited):
        visited.append(current)
        if current == end:
            return [current]
        for neighbor in self.get_neighbors(current):
            if neighbor not in visited:
                path = self.find_path(neighbor, end, visited)
                if path:
                    return [current] + path
        return None

    def get_neighbors(self, node):
        neighbors = []
        for edge in self.edges:
            if edge[0] == node:
                neighbors.append(edge[1])
        return neighbors

    def calculate_cost(self, path):
        cost = 0
        for i in range(len(path) - 1):
            for edge in self.edges:
                if edge[0] == path[i] and edge[1] == path[i + 1]:
                    cost += edge[2]
        return cost

def main():
    nodes = ['A', 'B', 'C', 'D']
    edges = [('A', 'B', 10), ('B', 'C', 20), ('C', 'D', 30), ('D', 'A', 40)]
    supply_chain = SupplyChain(nodes, edges)
    while True:
        cost = supply_chain.optimize('A', 'D')
        print(f'Optimized cost: {cost}')
main()