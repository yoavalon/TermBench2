class LogisticsSystem:

    def __init__(self, capacity):
        self.capacity = capacity
        self.current_load = 0

    def add_load(self, load):
        if self.current_load + load <= self.capacity:
            self.current_load += load
            return True
        return False

    def remove_load(self, load):
        if load <= self.current_load:
            self.current_load -= load
            return True
        return False

    def get_load_status(self):
        return (self.current_load, self.capacity - self.current_load)

class DemandHandler:

    def __init__(self, demand):
        self.demand = demand
        self.current_demand = demand

    def update_demand(self, change):
        self.current_demand += change
        if self.current_demand < 0:
            self.current_demand = 0

    def get_demand(self):
        return self.current_demand

class SupplyOptimizer:

    def __init__(self, logistics, demand_handler):
        self.logistics = logistics
        self.demand_handler = demand_handler

    def optimize(self):
        supply, remaining_capacity = self.logistics.get_load_status()
        demand = self.demand_handler.get_demand()
        if demand > supply:
            shortfall = demand - supply
            if self.logistics.add_load(shortfall):
                self.demand_handler.update_demand(-shortfall)
        elif supply > demand:
            excess = supply - demand
            self.logistics.remove_load(excess)

def main():
    logistics = LogisticsSystem(100)
    demand_handler = DemandHandler(50)
    optimizer = SupplyOptimizer(logistics, demand_handler)
    while True:
        optimizer.optimize()
main()