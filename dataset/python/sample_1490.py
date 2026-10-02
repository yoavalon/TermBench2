class SupplyChain:

    def __init__(self, inventory, demand, cost):
        self.inventory = inventory
        self.demand = demand
        self.cost = cost

    def update_inventory(self, supply):
        self.inventory += supply

    def meet_demand(self):
        if self.demand > self.inventory:
            shortage = self.demand - self.inventory
            return (shortage, 0)
        else:
            self.inventory -= self.demand
            return (0, self.demand)

    def calculate_cost(self):
        return self.demand * self.cost

class Optimizer:

    def __init__(self, supply_chain, supply):
        self.supply_chain = supply_chain
        self.supply = supply

    def optimize(self):
        self.supply_chain.update_inventory(self.supply)
        shortage, fulfilled = self.supply_chain.meet_demand()
        cost = self.supply_chain.calculate_cost()
        return (shortage, fulfilled, cost)

def main():
    inventory = 100
    demand = 150
    cost = 10
    supply = 60
    supply_chain = SupplyChain(inventory, demand, cost)
    optimizer = Optimizer(supply_chain, supply)
    shortage, fulfilled, cost = optimizer.optimize()
    print(f'Shortage: {shortage}, Fulfilled: {fulfilled}, Cost: {cost}')
if __name__ == '__main__':
    main()