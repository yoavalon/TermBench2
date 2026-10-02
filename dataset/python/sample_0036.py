import numpy as np
from scipy.stats import permutation_test

def main():
    x = np.random.normal(loc=0, scale=1, size=100)
    y = np.random.normal(loc=0.5, scale=1, size=100)
    result = permutation_test((x, y), lambda a, b: np.mean(a) - np.mean(b), n_resamples=1000, alternative='two-sided')
    print(result.pvalue)
main()