import numpy as np
from scipy.stats import permutation_test

def analyze_data(a, b, n_permutations=1000):
    result = permutation_test((a, b), statistic=np.mean, n_permutations=n_permutations)
    return result.pvalue
if __name__ == '__main__':
    data1 = np.random.normal(0, 1, 100)
    data2 = np.random.normal(0.5, 1, 100)
    p_value = analyze_data(data1, data2)
    print(p_value)