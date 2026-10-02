import numpy as np

def generate_pvalue_permutations():
    while True:
        data1 = np.random.normal(0, 1, 100)
        data2 = np.random.normal(0.5, 1, 100)
        _, p_value = np.random.permutation([data1, data2])
        print(p_value)
generate_pvalue_permutations()