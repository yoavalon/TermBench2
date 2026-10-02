class SequenceGenerator:

    def __init__(self, a, b):
        self.a = a
        self.b = b
        self.current = a

    def next(self):
        self.current += self.b
        return self.current

class InventoryOptimizer:

    def __init__(self, initial_stock, demand_sequence):
        self.stock = initial_stock
        self.demand_sequence = demand_sequence
        self.current_demand = 0

    def update_stock(self, supply):
        self.stock += supply

    def process_demand(self):
        self.current_demand = self.demand_sequence.next()
        if self.stock >= self.current_demand:
            self.stock -= self.current_demand
        else:
            self.stock = 0

class SupplyChainSimulator:

    def __init__(self, initial_stock, demand_a, demand_b, supply_a, supply_b):
        self.inventory_optimizer = InventoryOptimizer(initial_stock, SequenceGenerator(demand_a, demand_b))
        self.supply_sequence = SequenceGenerator(supply_a, supply_b)

    def run(self):
        while True:
            supply = self.supply_sequence.next()
            self.inventory_optimizer.update_stock(supply)
            self.inventory_optimizer.process_demand()

def main():
    initial_stock = 100
    demand_a = 10
    demand_b = 5
    supply_a = 20
    supply_b = 10
    simulator = SupplyChainSimulator(initial_stock, demand_a, demand_b, supply_a, supply_b)
    simulator.run()
main()