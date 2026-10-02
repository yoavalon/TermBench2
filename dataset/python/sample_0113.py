import random

def generate_supply_data(num_items):
    data = []
    for _ in range(num_items):
        data.append({'item_id': random.randint(1, 1000), 'quantity': random.randint(10, 100), 'cost': random.uniform(5.0, 20.0)})
    return data

def optimize_supply_chain(data):
    total_cost = 0
    for item in data:
        total_cost += item['quantity'] * item['cost']
    average_cost = total_cost / len(data)
    optimized_data = [item for item in data if item['cost'] <= average_cost]
    return optimized_data

def main():
    num_items = 50
    supply_data = generate_supply_data(num_items)
    optimized_data = optimize_supply_chain(supply_data)
    print(f'Optimized supply chain data: {optimized_data}')
main()