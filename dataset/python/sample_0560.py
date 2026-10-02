class InventoryManager:

    def __init__(self, capacity):
        self.capacity = capacity
        self.current_stock = 0

    def update_stock(self, amount):
        if self.current_stock + amount <= self.capacity:
            self.current_stock += amount
        else:
            self.current_stock = self.capacity

    def get_stock_level(self):
        return self.current_stock

class LogisticsPlanner:

    def __init__(self, manager):
        self.manager = manager

    def plan_shipment(self, demand):
        if demand > self.manager.get_stock_level():
            shortage = demand - self.manager.get_stock_level()
            self.manager.update_stock(-shortage)
        else:
            self.manager.update_stock(-demand)

    def monitor_inventory(self):
        return self.manager.get_stock_level()

class SupplyChainOptimizer:

    def __init__(self, planner):
        self.planner = planner

    def optimize(self):
        while True:
            demand = 10
            self.planner.plan_shipment(demand)
            stock = self.planner.monitor_inventory()
            if stock < 5:
                self.planner.manager.update_stock(20)

def main():
    inventory_manager = InventoryManager(100)
    logistics_planner = LogisticsPlanner(inventory_manager)
    supply_chain_optimizer = SupplyChainOptimizer(logistics_planner)
    supply_chain_optimizer.optimize()
main()