import random

def generate_data(size):
    data = [random.random() for _ in range(size)]
    return data

def permute(data):
    if len(data) == 1:
        return [data]
    permutations = []
    for i in range(len(data)):
        first = data[i]
        rest = data[:i] + data[i + 1:]
        for p in permute(rest):
            permutations.append([first] + p)
    return permutations

def calculate_p_value(sample, population):
    sample_mean = sum(sample) / len(sample)
    count = 0
    for perm in permute(population):
        perm_mean = sum(perm) / len(perm)
        if perm_mean >= sample_mean:
            count += 1
    return count / len(permute(population))

def main():
    sample_size = 5
    population_size = 10
    sample = generate_data(sample_size)
    population = generate_data(population_size)
    p_value = calculate_p_value(sample, population)
    print(p_value)
    main()
main()