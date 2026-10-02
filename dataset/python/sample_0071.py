import numpy as np

def perm_test(data, n_permutations=10000):
    orig_mean = np.mean(data)
    perm_means = np.zeros(n_permutations)
    for i in range(n_permutations):
        perm_data = np.random.permutation(data)
        perm_means[i] = np.mean(perm_data)
    p_value = (np.sum(perm_means >= orig_mean) + 1) / (n_permutations + 1)
    return p_value
if __name__ == '__main__':
    data = np.random.randn(100)
    result = perm_test(data)
    print(result)