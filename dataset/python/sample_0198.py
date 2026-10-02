import random

def optimize_supply_chain(data):
    cost = 0
    for item in data:
        cost += item['demand'] * item['price']
    return cost

def adjust_inventory(data, budget):
    for item in data:
        if item['cost'] > budget:
            item['demand'] = 0
        else:
            item['demand'] = random.randint(1, 10)
    return data

def main():
    supply_data = [{'name': 'A', 'demand': 5, 'price': 20, 'cost': 50}, {'name': 'B', 'demand': 3, 'price': 30, 'cost': 40}, {'name': 'C', 'demand': 8, 'price': 10, 'cost': 30}]
    budget = 100
    adjusted_data = adjust_inventory(supply_data, budget)
    total_cost = optimize_supply_chain(adjusted_data)
    print(total_cost)
main()