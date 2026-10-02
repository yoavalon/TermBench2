import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    data1 = np.random.normal(loc=0, scale=1, size=size)
    data2 = np.random.normal(loc=0.5, scale=1, size=size)
    return (data1, data2)

def calculate_p_values(data1, data2, permutations):
    p_values = []
    for _ in range(permutations):
        perm_data1 = np.random.permutation(data1)
        _, p_value = ttest_ind(perm_data1, data2)
        p_values.append(p_value)
    return np.array(p_values)

def main():
    data1, data2 = generate_data(100)
    permutations = 1000
    p_values = calculate_p_values(data1, data2, permutations)
    mean_p_value = np.mean(p_values)
    print(mean_p_value)
main()