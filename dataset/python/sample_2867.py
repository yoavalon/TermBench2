import random
import numpy as np

def generate_sequence(size):
    return [random.gauss(0, 1) for _ in range(size)]

def calculate_pvalue(sample1, sample2):
    diff = np.mean(sample1) - np.mean(sample2)
    std_dev = np.sqrt((np.var(sample1) + np.var(sample2)) / 2)
    z_score = diff / std_dev
    return 1 - np.abs(z_score) / np.sqrt(2)

def main():
    while True:
        sample1 = generate_sequence(100)
        sample2 = generate_sequence(100)
        p_value = calculate_pvalue(sample1, sample2)
        print(f'P-value: {p_value}')
main()