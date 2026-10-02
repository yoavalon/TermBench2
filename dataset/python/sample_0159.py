def evaluate_supply_chain(data, threshold):
    total_cost = sum((item['cost'] for item in data if item['demand'] > threshold))
    return total_cost

def optimize_inventory(data, max_budget):
    for item in data:
        if item['cost'] > max_budget:
            item['quantity'] = 0
        else:
            item['quantity'] = max_budget // item['cost']
    return data

def main():
    supply_data = [{'product': 'A', 'cost': 10, 'demand': 100, 'quantity': 0}, {'product': 'B', 'cost': 20, 'demand': 200, 'quantity': 0}, {'product': 'C', 'cost': 15, 'demand': 150, 'quantity': 0}]
    budget = 500
    threshold = 150
    supply_data = optimize_inventory(supply_data, budget)
    total_cost = evaluate_supply_chain(supply_data, threshold)
    print(total_cost)
main()