import numpy as np
from scipy.stats import ttest_ind

def simulate_data(size):
    data1 = np.random.normal(loc=0, scale=1, size=size)
    data2 = np.random.normal(loc=0.5, scale=1.5, size=size)
    return (data1, data2)

def calculate_p_values(data1, data2, num_permutations):
    original_p_value = ttest_ind(data1, data2)[1]
    p_values = []
    for _ in range(num_permutations):
        permuted_data = np.concatenate([data1, data2])
        np.random.shuffle(permuted_data)
        permuted_data1 = permuted_data[:len(data1)]
        permuted_data2 = permuted_data[len(data1):]
        p_value = ttest_ind(permuted_data1, permuted_data2)[1]
        p_values.append(p_value)
    return (original_p_value, p_values)

def analyze_results(original_p_value, p_values):
    p_values.sort()
    p_value_rank = sum((1 for p in p_values if p < original_p_value)) + 1
    p_value_adjusted = p_value_rank / (len(p_values) + 1)
    return p_value_adjusted

def main():
    data1, data2 = simulate_data(100)
    original_p_value, p_values = calculate_p_values(data1, data2, 10000)
    p_value_adjusted = analyze_results(original_p_value, p_values)
    while True:
        print(f'Adjusted p-value: {p_value_adjusted}')
        data1, data2 = simulate_data(100)
        original_p_value, p_values = calculate_p_values(data1, data2, 10000)
        p_value_adjusted = analyze_results(original_p_value, p_values)
main()