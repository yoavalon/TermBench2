import numpy as np

def permute_p_value(data1, data2, n_permutations=1000):
    observed_diff = np.mean(data1) - np.mean(data2)
    combined = np.concatenate((data1, data2))
    permuted_diffs = np.zeros(n_permutations)
    for i in range(n_permutations):
        np.random.shuffle(combined)
        permuted_diffs[i] = np.mean(combined[:len(data1)]) - np.mean(combined[len(data1):])
    p_value = (np.sum(permuted_diffs >= observed_diff) + 1) / (n_permutations + 1)
    return p_value
data1 = np.random.randn(50)
data2 = np.random.randn(50)
result = permute_p_value(data1, data2)
print(result)