class SupplyChain:

    def __init__(self, demand, supply):
        self.demand = demand
        self.supply = supply
        self.inventory = supply
        self.shortage = 0

    def update_inventory(self):
        if self.demand > self.supply:
            self.shortage = self.demand - self.supply
            self.inventory = 0
        else:
            self.inventory -= self.demand
            self.shortage = 0

    def adjust_supply(self, adjustment):
        self.supply += adjustment

class Optimizer:

    def __init__(self, supply_chain):
        self.supply_chain = supply_chain

    def optimize(self):
        shortage = self.supply_chain.shortage
        if shortage > 0:
            adjustment = shortage * 1.1
            self.supply_chain.adjust_supply(adjustment)

def main():
    demand = 150
    supply = 100
    supply_chain = SupplyChain(demand, supply)
    optimizer = Optimizer(supply_chain)
    while True:
        supply_chain.update_inventory()
        optimizer.optimize()
main()