import random

def generate_shipments(data):
    mutated_data = []
    for item in data:
        new_item = item.copy()
        new_item['quantity'] = int(new_item['quantity'] * random.uniform(0.8, 1.2))
        new_item['lead_time'] = int(new_item['lead_time'] * random.uniform(0.9, 1.1))
        mutated_data.append(new_item)
    return mutated_data

def optimize_inventory(data):
    optimized_data = []
    for item in data:
        if item['quantity'] > 100:
            item['quantity'] = 100
        if item['lead_time'] < 5:
            item['lead_time'] = 5
        optimized_data.append(item)
    return optimized_data

def main():
    initial_data = [{'item': 'A', 'quantity': 120, 'lead_time': 4}, {'item': 'B', 'quantity': 90, 'lead_time': 6}, {'item': 'C', 'quantity': 150, 'lead_time': 3}]
    mutated_data = generate_shipments(initial_data)
    optimized_data = optimize_inventory(mutated_data)
    print(optimized_data)
main()