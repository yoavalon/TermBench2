import random

def generate_supply_chain(data):
    mutated_data = []
    for item in data:
        mutation_factor = random.uniform(0.9, 1.1)
        mutated_value = item * mutation_factor
        mutated_data.append(mutated_value)
    return mutated_data

def optimize_logistics(data):
    optimized_data = []
    for value in data:
        if value > 100:
            optimized_value = value * 0.95
        else:
            optimized_value = value * 1.05
        optimized_data.append(optimized_value)
    return optimized_data

def main():
    initial_data = [random.randint(50, 150) for _ in range(10)]
    mutated_data = generate_supply_chain(initial_data)
    optimized_data = optimize_logistics(mutated_data)
    print(optimized_data)
main()