import random

def generate_data(n):
    return [random.random() for _ in range(n)]

def calculate_p_values(data, n_permutations):
    p_values = []
    for _ in range(n_permutations):
        random.shuffle(data)
        statistic = sum(data) / len(data)
        p_values.append(statistic)
    return p_values

def analyze_p_values(p_values, threshold):
    return [p < threshold for p in p_values]

def main():
    data_size = 100
    permutations = 1000
    threshold = 0.5
    data = generate_data(data_size)
    p_values = calculate_p_values(data, permutations)
    results = analyze_p_values(p_values, threshold)
    print(results)
main()