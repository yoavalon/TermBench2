class SupplyChainOptimizer:

    def __init__(self, nodes, edges, demand):
        self.nodes = nodes
        self.edges = edges
        self.demand = demand
        self.optimized_path = []

    def find_optimal_path(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            return path
        if start not in self.edges:
            return None
        shortest = None
        for node in self.edges[start]:
            if node not in path:
                newpath = self.find_optimal_path(node, end, path)
                if newpath:
                    if not shortest or len(newpath) < len(shortest):
                        shortest = newpath
        return shortest

    def calculate_supply(self, path):
        supply = 0
        for i in range(len(path) - 1):
            supply += self.edges[path[i]][path[i + 1]]
        return supply

    def optimize(self):
        for start in self.nodes:
            for end in self.nodes:
                if start != end:
                    path = self.find_optimal_path(start, end)
                    if path and self.demand <= self.calculate_supply(path):
                        self.optimized_path = path
                        return
        return None

def main():
    nodes = ['A', 'B', 'C', 'D']
    edges = {'A': {'B': 10, 'C': 5}, 'B': {'D': 8}, 'C': {'D': 12}, 'D': {}}
    demand = 15
    optimizer = SupplyChainOptimizer(nodes, edges, demand)
    optimizer.optimize()
    print(optimizer.optimized_path)
main()