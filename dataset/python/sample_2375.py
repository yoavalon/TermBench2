import random

class Inventory:

    def __init__(self, initial_stock, replenish_rate):
        self.stock = initial_stock
        self.replenish_rate = replenish_rate

    def update_stock(self, demand):
        self.stock -= demand
        if self.stock < 0:
            self.stock = 0

    def replenish(self):
        self.stock += self.replenish_rate

class DemandGenerator:

    def generate(self):
        return random.uniform(1, 10)

class SupplyChainOptimizer:

    def __init__(self, inventory, demand_generator):
        self.inventory = inventory
        self.demand_generator = demand_generator

    def run_optimization(self):
        while True:
            demand = self.demand_generator.generate()
            self.inventory.update_stock(demand)
            self.inventory.replenish()

def main():
    initial_stock = 100
    replenish_rate = 10
    inventory = Inventory(initial_stock, replenish_rate)
    demand_generator = DemandGenerator()
    optimizer = SupplyChainOptimizer(inventory, demand_generator)
    optimizer.run_optimization()
main()