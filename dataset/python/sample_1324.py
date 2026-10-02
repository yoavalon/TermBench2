import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    group1 = np.random.normal(loc=5, scale=2, size=size)
    group2 = np.random.normal(loc=5.5, scale=2.5, size=size)
    return (group1, group2)

def calculate_pvalue_permutations(group1, group2, iterations):
    pvalues = []
    for _ in range(iterations):
        combined = np.concatenate((group1, group2))
        np.random.shuffle(combined)
        permuted_group1 = combined[:len(group1)]
        permuted_group2 = combined[len(group1):]
        _, p = ttest_ind(permuted_group1, permuted_group2)
        pvalues.append(p)
    return pvalues

def main():
    group1, group2 = generate_data(30)
    permutations = 1000
    pvalues = calculate_pvalue_permutations(group1, group2, permutations)
    print(np.mean(pvalues))
if __name__ == '__main__':
    main()