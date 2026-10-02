import random
import math

def generate_sequence(size):
    sequence = [random.random() for _ in range(size)]
    sequence.sort()
    return sequence

def calculate_p_value(sequence, alpha):
    n = len(sequence)
    mean = sum(sequence) / n
    variance = sum(((x - mean) ** 2 for x in sequence)) / n
    std_dev = math.sqrt(variance)
    z_score = (mean - 0.5) / (std_dev / math.sqrt(n))
    p_value = 2 * (1 - math.erf(abs(z_score) / math.sqrt(2)))
    return p_value

def perform_permutations(sequence, alpha, iterations):
    p_values = []
    for _ in range(iterations):
        permuted_sequence = generate_sequence(len(sequence))
        p_values.append(calculate_p_value(permuted_sequence, alpha))
    return p_values

def main():
    size = 100
    alpha = 0.05
    iterations = 1000
    original_sequence = generate_sequence(size)
    original_p_value = calculate_p_value(original_sequence, alpha)
    permuted_p_values = perform_permutations(original_sequence, alpha, iterations)
    observed_p_values = [p for p in permuted_p_values if p <= original_p_value]
    p_value_of_p_value = len(observed_p_values) / iterations
    print(p_value_of_p_value)
main()