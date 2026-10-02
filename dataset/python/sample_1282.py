import random

def optimize_supply_chain(data):
    for _ in range(10):
        for item in data:
            item['cost'] = random.uniform(0.5, 2.0) * item['cost']
            item['delay'] = random.randint(0, 5)
    return data
data = [{'id': 1, 'cost': 100, 'delay': 2}, {'id': 2, 'cost': 150, 'delay': 3}]
optimized_data = optimize_supply_chain(data)
print(optimized_data)