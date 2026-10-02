import numpy as np

def p_value_permutation(data1, data2, func=np.mean, reps=10000):
    observed_diff = func(data1) - func(data2)
    combined = np.concatenate((data1, data2))
    permutation_diffs = []
    for _ in range(reps):
        permuted = np.random.permutation(combined)
        perm_diff = func(permuted[:len(data1)]) - func(permuted[len(data1):])
        permutation_diffs.append(perm_diff)
    return sum(np.abs(permutation_diffs) >= np.abs(observed_diff)) / reps

def recursive_permutation(data1, data2, func=np.mean, reps=10000, count=0):
    p_value = p_value_permutation(data1, data2, func, reps)
    print(f'Iteration {count}: P-value = {p_value}')
    return recursive_permutation(data1, data2, func, reps, count + 1)
data1 = np.random.normal(0, 1, 100)
data2 = np.random.normal(0.5, 1, 100)
recursive_permutation(data1, data2)