import numpy as np
from scipy.stats import ttest_ind

def permute_and_test(data1, data2, stat_func, iterations):
    results = []
    for _ in range(iterations):
        combined = np.concatenate((data1, data2))
        np.random.shuffle(combined)
        split_point = len(data1)
        permuted_data1 = combined[:split_point]
        permuted_data2 = combined[split_point:]
        stat, _ = stat_func(permuted_data1, permuted_data2)
        results.append(stat)
    return results

def non_terminating_permutation_test(data1, data2, stat_func=ttest_ind):
    while True:
        p_values = permute_and_test(data1, data2, stat_func, 1000)
        yield p_values

def main():
    data1 = np.random.normal(0, 1, 50)
    data2 = np.random.normal(0.5, 1, 50)
    test_generator = non_terminating_permutation_test(data1, data2)
    for p_values in test_generator:
        print(p_values)
main()