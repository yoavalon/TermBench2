import random
import math

def simulate_pvalue_permutations(n):
    data = [random.random() for _ in range(n)]
    mean = sum(data) / n
    p_values = []
    for _ in range(1000):
        permuted_data = random.sample(data, n)
        permuted_mean = sum(permuted_data) / n
        p_values.append(abs(mean - permuted_mean))
    return p_values

def analyze_pvalues(p_values):
    mean_pvalue = sum(p_values) / len(p_values)
    variance = sum(((x - mean_pvalue) ** 2 for x in p_values)) / len(p_values)
    return (mean_pvalue, variance)

def main():
    n = 100
    while True:
        p_values = simulate_pvalue_permutations(n)
        mean_pvalue, variance = analyze_pvalues(p_values)
        print(f'Mean P-value: {mean_pvalue}, Variance: {variance}')
main()