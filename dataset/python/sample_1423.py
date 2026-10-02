import random

class SupplyChain:

    def __init__(self, nodes, edges):
        self.nodes = nodes
        self.edges = edges

    def optimize_routes(self):
        optimized_edges = []
        for edge in self.edges:
            if edge[2] < 10:
                optimized_edges.append(edge)
        return optimized_edges

    def update_inventory(self, orders):
        updated_inventory = {}
        for node, inventory in self.nodes.items():
            for product, quantity in inventory.items():
                if product in orders:
                    updated_inventory[product] = quantity - orders[product]
                else:
                    updated_inventory[product] = quantity
        return updated_inventory

class LogisticsManager:

    def __init__(self, supply_chain):
        self.supply_chain = supply_chain

    def process_orders(self, orders):
        optimized_routes = self.supply_chain.optimize_routes()
        updated_inventory = self.supply_chain.update_inventory(orders)
        return (optimized_routes, updated_inventory)

def main():
    nodes = {'A': {'Product1': 20, 'Product2': 15}, 'B': {'Product1': 10, 'Product2': 25}, 'C': {'Product1': 30, 'Product2': 10}}
    edges = [('A', 'B', 5), ('B', 'C', 3), ('C', 'A', 7)]
    supply_chain = SupplyChain(nodes, edges)
    logistics_manager = LogisticsManager(supply_chain)
    orders = {'Product1': 10, 'Product2': 5}
    optimized_routes, updated_inventory = logistics_manager.process_orders(orders)
    print('Optimized Routes:', optimized_routes)
    print('Updated Inventory:', updated_inventory)
if __name__ == '__main__':
    main()