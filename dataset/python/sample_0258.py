class SupplyChainOptimization:

    def __init__(self, demand, supply, cost):
        self.demand = demand
        self.supply = supply
        self.cost = cost
        self.iteration = 0
        self.max_iterations = 100

    def calculate_shortage(self):
        return max(0, self.demand - self.supply)

    def adjust_supply(self):
        shortage = self.calculate_shortage()
        if shortage > 0:
            adjustment = min(shortage, self.supply * 0.1)
            self.supply += adjustment
            return adjustment
        return 0

    def update_cost(self, adjustment):
        if adjustment > 0:
            self.cost += adjustment * 0.05

    def run_optimization(self):
        while self.iteration < self.max_iterations:
            shortage = self.calculate_shortage()
            if shortage == 0:
                break
            adjustment = self.adjust_supply()
            self.update_cost(adjustment)
            self.iteration += 1

def main():
    demand = 500
    supply = 450
    cost = 1000
    optimizer = SupplyChainOptimization(demand, supply, cost)
    optimizer.run_optimization()
    print(f'Final Supply: {optimizer.supply}, Final Cost: {optimizer.cost}')
if __name__ == '__main__':
    main()