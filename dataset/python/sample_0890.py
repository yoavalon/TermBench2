class SupplyChainOptimizer:

    def __init__(self, nodes, edges, demand):
        self.nodes = nodes
        self.edges = edges
        self.demand = demand
        self.path = []

    def optimize(self):
        self._find_path(0, 0, 0)

    def _find_path(self, current_node, current_cost, current_demand):
        if current_node == len(self.nodes) - 1:
            if current_demand == self.demand:
                self.path.append(current_node)
                return True
            return False
        for neighbor, cost in self.edges[current_node]:
            if self._find_path(neighbor, current_cost + cost, current_demand + 1):
                self.path.insert(0, current_node)
                return True
        return False

class DemandBalancer:

    def __init__(self, nodes, edges, demand):
        self.optimizer = SupplyChainOptimizer(nodes, edges, demand)

    def balance(self):
        self.optimizer.optimize()
        return self.optimizer.path

def main():
    nodes = [0, 1, 2, 3, 4]
    edges = {0: [(1, 10), (2, 15)], 1: [(3, 5)], 2: [(3, 10)], 3: [(4, 20)], 4: []}
    demand = 3
    balancer = DemandBalancer(nodes, edges, demand)
    result = balancer.balance()
    print(result)
if __name__ == '__main__':
    main()