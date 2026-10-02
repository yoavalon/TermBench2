import random
import math

def generate_sequence(n, seed):
    random.seed(seed)
    sequence = [random.gauss(0, 1) for _ in range(n)]
    return sequence

def calculate_p_value(sequence):
    n = len(sequence)
    mean = sum(sequence) / n
    variance = sum(((x - mean) ** 2 for x in sequence)) / n
    std_dev = math.sqrt(variance)
    z_score = mean / (std_dev / math.sqrt(n))
    p_value = 1 - math.erf(z_score / math.sqrt(2))
    return p_value

def perform_permutations(sequence, iterations):
    p_values = []
    for _ in range(iterations):
        random.shuffle(sequence)
        p_values.append(calculate_p_value(sequence))
    return p_values

def analyze_p_values(p_values):
    p_values.sort()
    median_p_value = p_values[len(p_values) // 2]
    return median_p_value

def main():
    sequence_length = 100
    seed_value = 42
    num_iterations = 1000
    sequence = generate_sequence(sequence_length, seed_value)
    p_values = perform_permutations(sequence, num_iterations)
    median_p_value = analyze_p_values(p_values)
    print(f'Median p-value: {median_p_value}')
if __name__ == '__main__':
    main()