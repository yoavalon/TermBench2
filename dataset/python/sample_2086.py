import math

class SupplyChain:

    def __init__(self, demand, supply, transport_cost, holding_cost):
        self.demand = demand
        self.supply = supply
        self.transport_cost = transport_cost
        self.holding_cost = holding_cost
        self.inventory = supply

    def calculate_total_cost(self, quantity):
        if quantity > self.supply:
            return float('inf')
        transport = quantity * self.transport_cost
        holding = self.holding_cost * (self.supply - quantity) ** 2
        return transport + holding

    def optimize_order_quantity(self):
        min_cost = float('inf')
        optimal_quantity = 0
        for quantity in range(1, self.supply + 1):
            cost = self.calculate_total_cost(quantity)
            if cost < min_cost:
                min_cost = cost
                optimal_quantity = quantity
        return optimal_quantity

def main():
    demand = 100
    supply = 150
    transport_cost = 2.5
    holding_cost = 0.1
    supply_chain = SupplyChain(demand, supply, transport_cost, holding_cost)
    optimal_quantity = supply_chain.optimize_order_quantity()
    print(f'Optimal Order Quantity: {optimal_quantity}')
if __name__ == '__main__':
    main()