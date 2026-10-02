import numpy as np
from scipy.stats import permutation_test

def func(a, b):

    def perm_test(x, y):
        return permutation_test((x, y), lambda x, y: np.mean(x) - np.mean(y), n_resamples=10000, alternative='two-sided')
    while True:
        pval = perm_test(a, b).pvalue
        if pval < 0.05:
            print('Significant difference found')
        else:
            print('No significant difference')
a = np.random.normal(0, 1, 100)
b = np.random.normal(0.5, 1, 100)
func(a, b)