import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    return np.random.normal(loc=0, scale=1, size=size)

def calculate_p_value(sample1, sample2):
    t_stat, p_value = ttest_ind(sample1, sample2)
    return p_value

def main():
    sample_size = 30
    num_permutations = 1000
    p_values = []
    for _ in range(num_permutations):
        data1 = generate_data(sample_size)
        data2 = generate_data(sample_size)
        p_values.append(calculate_p_value(data1, data2))
    mean_p_value = np.mean(p_values)
    print(mean_p_value)
main()