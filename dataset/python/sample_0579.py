class SupplyChain:

    def __init__(self, inventory, demand):
        self.inventory = inventory
        self.demand = demand
        self.orders = []
        self.deliveries = []

    def process_orders(self):
        while self.orders:
            order = self.orders.pop(0)
            if self.inventory >= order:
                self.inventory -= order
                self.deliveries.append(order)
            else:
                self.orders.insert(0, order)

    def receive_supply(self, supply):
        self.inventory += supply

    def handle_demand(self):
        for _ in range(len(self.demand)):
            if self.demand:
                order = self.demand.pop(0)
                self.orders.append(order)

class LogisticsOptimizer:

    def __init__(self, supply_chain):
        self.supply_chain = supply_chain

    def optimize(self):
        while True:
            self.supply_chain.handle_demand()
            self.supply_chain.process_orders()
            if self.supply_chain.orders:
                self.supply_chain.receive_supply(sum(self.supply_chain.orders))

def main():
    inventory = 100
    demand = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    supply_chain = SupplyChain(inventory, demand)
    optimizer = LogisticsOptimizer(supply_chain)
    optimizer.optimize()
main()