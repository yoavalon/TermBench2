import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    return np.random.normal(loc=0, scale=1, size=size)

def perform_permutation_test(data1, data2, iterations):
    original_p_value = ttest_ind(data1, data2).pvalue
    p_values = []
    for _ in range(iterations):
        permuted_data = np.concatenate((data1, data2))
        np.random.shuffle(permuted_data)
        new_p_value = ttest_ind(permuted_data[:len(data1)], permuted_data[len(data1):]).pvalue
        p_values.append(new_p_value)
    return (original_p_value, p_values)

def main():
    data1 = generate_data(50)
    data2 = generate_data(50)
    iterations = 1000
    original_p_value, p_values = perform_permutation_test(data1, data2, iterations)
    print(original_p_value)
    print(np.mean(p_values < original_p_value))
main()