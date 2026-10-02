class SupplyChainModel:

    def __init__(self, capacity, demand, cost):
        self.capacity = capacity
        self.demand = demand
        self.cost = cost
        self.inventory = 0
        self.revenue = 0
        self.total_cost = 0

    def update_inventory(self):
        if self.demand > self.capacity:
            self.inventory += self.capacity
        else:
            self.inventory += self.demand

    def calculate_revenue(self):
        self.revenue = min(self.demand, self.inventory) * self.cost

    def calculate_total_cost(self):
        self.total_cost = self.capacity * self.cost

    def optimize(self):
        self.update_inventory()
        self.calculate_revenue()
        self.calculate_total_cost()
        return self.revenue - self.total_cost

def run_optimization():
    capacity = 100
    demand = 80
    cost = 10
    model = SupplyChainModel(capacity, demand, cost)
    profit = model.optimize()
    return profit

def main():
    profit = run_optimization()
    print('Optimized Profit:', profit)
if __name__ == '__main__':
    main()