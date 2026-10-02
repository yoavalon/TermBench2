class SupplyChainOptimization:

    def __init__(self, demand_sequence, production_capacity):
        self.demand_sequence = demand_sequence
        self.production_capacity = production_capacity
        self.inventory = 0
        self.backlog = 0
        self.total_cost = 0
        self.production_plan = []

    def calculate_production(self, demand):
        if demand > self.production_capacity:
            production = self.production_capacity
            self.backlog += demand - self.production_capacity
        else:
            production = demand
        return production

    def update_inventory(self, production, demand):
        self.inventory += production - demand

    def update_cost(self, production, demand):
        if self.backlog > 0:
            self.total_cost += self.backlog * 10
        self.total_cost += production * 5

    def run_optimization(self):
        for demand in self.demand_sequence:
            production = self.calculate_production(demand)
            self.production_plan.append(production)
            self.update_inventory(production, demand)
            self.update_cost(production, demand)

def main():
    demand_sequence = [100, 150, 200, 250, 300, 350, 400, 450, 500, 550]
    production_capacity = 250
    optimizer = SupplyChainOptimization(demand_sequence, production_capacity)
    optimizer.run_optimization()
    print('Total Cost:', optimizer.total_cost)
    print('Final Inventory:', optimizer.inventory)
    print('Final Backlog:', optimizer.backlog)
    print('Production Plan:', optimizer.production_plan)
if __name__ == '__main__':
    main()