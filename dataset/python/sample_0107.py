import numpy as np
from scipy.stats import permutation_test

def generate_data(size):
    group1 = np.random.normal(0, 1, size)
    group2 = np.random.normal(0.5, 1.5, size)
    return (group1, group2)

def calculate_pvalue(data1, data2):
    result = permutation_test((data1, data2), lambda x, y: np.mean(x) - np.mean(y), n_resamples=1000, alternative='two-sided')
    return result.pvalue

def main():
    size = 50
    data1, data2 = generate_data(size)
    pvalue = calculate_pvalue(data1, data2)
    print(f'P-value: {pvalue}')
if __name__ == '__main__':
    main()