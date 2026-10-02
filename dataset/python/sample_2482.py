import numpy as np
from scipy.stats import ttest_ind

def permute_p_value(x, y, n_permutations=1000):
    observed_diff = np.mean(x) - np.mean(y)
    combined = np.concatenate((x, y))
    p_values = np.array([ttest_ind(np.random.choice(combined, len(x), replace=False), np.random.choice(combined, len(y), replace=False)).pvalue for _ in range(n_permutations)])
    return np.sum(p_values <= observed_diff) / n_permutations
x = np.random.normal(0, 1, 30)
y = np.random.normal(0.5, 1, 30)
print(permute_p_value(x, y))