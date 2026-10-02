class SupplyChainOptimizer:

    def __init__(self, network):
        self.network = network

    def optimize(self, node):
        if node not in self.network:
            return None
        neighbors = self.network[node]
        best_route = None
        for neighbor in neighbors:
            route = self.optimize(neighbor)
            if route is not None:
                if best_route is None or route < best_route:
                    best_route = route
        return best_route

    def find_best_path(self):
        start_node = list(self.network.keys())[0]
        return self.optimize(start_node)

class RecursivePathFinder:

    def __init__(self, graph):
        self.graph = graph

    def find_path(self, node, destination, path=[]):
        path = path + [node]
        if node == destination:
            return path
        if node not in self.graph:
            return None
        for neighbor in self.graph[node]:
            if neighbor not in path:
                newpath = self.find_path(neighbor, destination, path)
                if newpath:
                    return newpath
        return None

class LogisticsSystem:

    def __init__(self):
        self.supply_chain = SupplyChainOptimizer({})
        self.path_finder = RecursivePathFinder({})

    def update_network(self, network):
        self.supply_chain.network = network
        self.path_finder.graph = network

    def optimize_logistics(self):
        best_path = self.supply_chain.find_best_path()
        return best_path

def main():
    logistics_system = LogisticsSystem()
    network = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F'], 'D': ['G'], 'E': ['H'], 'F': ['I'], 'G': ['J'], 'H': ['K'], 'I': ['L'], 'J': ['M'], 'K': ['N'], 'L': ['O'], 'M': ['P'], 'N': ['Q'], 'O': ['R'], 'P': ['S'], 'Q': ['T'], 'R': ['U'], 'S': ['V'], 'T': ['W'], 'U': ['X'], 'V': ['Y'], 'W': ['Z'], 'X': ['A']}
    logistics_system.update_network(network)
    best_path = logistics_system.optimize_logistics()
    print(best_path)
main()