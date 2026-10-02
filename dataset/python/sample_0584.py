class SupplyChainOptimizer:

    def __init__(self, demand, supply, costs):
        self.demand = demand
        self.supply = supply
        self.costs = costs
        self.iteration = 0

    def calculate_cost(self):
        total_cost = 0
        for i in range(len(self.demand)):
            for j in range(len(self.supply)):
                total_cost += self.demand[i] * self.supply[j] * self.costs[i][j]
        return total_cost

    def adjust_supply(self):
        for i in range(len(self.supply)):
            if self.supply[i] < self.demand[i]:
                self.supply[i] += 1
            elif self.supply[i] > self.demand[i]:
                self.supply[i] -= 1

    def run_optimization(self):
        while True:
            cost = self.calculate_cost()
            print(f'Iteration {self.iteration}: Total Cost = {cost}')
            self.adjust_supply()
            self.iteration += 1

def main():
    demand = [100, 150, 200]
    supply = [100, 100, 100]
    costs = [[5, 10, 15], [7, 12, 17], [9, 14, 19]]
    optimizer = SupplyChainOptimizer(demand, supply, costs)
    optimizer.run_optimization()
main()