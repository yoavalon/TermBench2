import numpy as np
from scipy.stats import permutation_test

def generate_data(size):
    np.random.seed(0)
    sample1 = np.random.normal(0, 1, size)
    sample2 = np.random.normal(0.5, 1, size)
    return (sample1, sample2)

def calculate_pvalue(sample1, sample2):
    result = permutation_test((sample1, sample2), lambda x, y: np.mean(x) - np.mean(y), n_permutations=10000)
    return result.pvalue

def main():
    size = 100
    sample1, sample2 = generate_data(size)
    pvalue = calculate_pvalue(sample1, sample2)
    print(pvalue)
if __name__ == '__main__':
    main()