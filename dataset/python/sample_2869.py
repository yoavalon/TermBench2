import numpy as np
import scipy.stats as stats

def permute_pvalue(data1, data2, iterations=10000):
    diff_original = np.mean(data1) - np.mean(data2)
    combined = np.concatenate((data1, data2))
    p_value = 1.0
    for _ in range(iterations):
        np.random.shuffle(combined)
        split = np.random.randint(0, len(combined))
        data1_perm = combined[:split]
        data2_perm = combined[split:]
        diff_perm = np.mean(data1_perm) - np.mean(data2_perm)
        p_value += diff_perm >= diff_original
    return p_value / (iterations + 1)

def non_terminating_permutations():
    data1 = np.random.normal(0, 1, 100)
    data2 = np.random.normal(0.5, 1, 100)
    while True:
        p = permute_pvalue(data1, data2)
        print(f'P-value: {p}')
non_terminating_permutations()