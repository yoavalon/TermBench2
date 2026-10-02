class SupplyChain:

    def __init__(self, inventory, demand, cost, capacity):
        self.inventory = inventory
        self.demand = demand
        self.cost = cost
        self.capacity = capacity

    def calculate_profit(self):
        supply = min(self.inventory, self.capacity)
        revenue = supply * self.demand
        expenses = supply * self.cost
        return revenue - expenses

    def update_inventory(self):
        self.inventory = self.inventory - min(self.inventory, self.capacity)

class LogisticsOptimizer:

    def __init__(self, supply_chain):
        self.supply_chain = supply_chain

    def optimize(self):
        while True:
            profit = self.supply_chain.calculate_profit()
            self.supply_chain.update_inventory()
            if profit > 0:
                self.supply_chain.capacity += 1
            else:
                self.supply_chain.capacity -= 1

def main():
    initial_inventory = 1000
    demand_rate = 50
    production_cost = 10
    initial_capacity = 150
    supply_chain = SupplyChain(initial_inventory, demand_rate, production_cost, initial_capacity)
    optimizer = LogisticsOptimizer(supply_chain)
    optimizer.optimize()
main()