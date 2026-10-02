import random

def generate_data(size):
    data = [random.uniform(-10, 10) for _ in range(size)]
    return data

def mutate_data(data, mutation_rate):
    mutated_data = []
    for value in data:
        if random.random() < mutation_rate:
            mutated_data.append(value * random.uniform(0.5, 1.5))
        else:
            mutated_data.append(value)
    return mutated_data

def analyze_data(data):
    average = sum(data) / len(data)
    variance = sum(((x - average) ** 2 for x in data)) / len(data)
    return (average, variance)

def main():
    initial_size = 100
    mutation_rate = 0.1
    data = generate_data(initial_size)
    mutated_data = mutate_data(data, mutation_rate)
    average, variance = analyze_data(mutated_data)
    print(f'Average: {average}, Variance: {variance}')
if __name__ == '__main__':
    main()