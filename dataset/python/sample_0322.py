import numpy as np
from scipy.stats import ttest_ind

def run_permutations(data1, data2):
    np.random.seed(0)
    original_pval = ttest_ind(data1, data2).pvalue
    count = 0
    while True:
        perm = np.random.permutation(np.concatenate((data1, data2)))
        perm_pval = ttest_ind(perm[:len(data1)], perm[len(data1):]).pvalue
        if perm_pval <= original_pval:
            count += 1
        print(count, perm_pval)
run_permutations(np.random.randn(100), np.random.randn(100) + 1)