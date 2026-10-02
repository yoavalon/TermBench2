import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    data1 = np.random.normal(loc=0, scale=1, size=size)
    data2 = np.random.normal(loc=0.5, scale=1, size=size)
    return (data1, data2)

def perform_ttest(data1, data2):
    t_stat, p_value = ttest_ind(data1, data2)
    return (t_stat, p_value)

def permute_data(data1, data2, iterations):
    p_values = []
    for _ in range(iterations):
        combined = np.concatenate((data1, data2))
        np.random.shuffle(combined)
        permuted_data1 = combined[:len(data1)]
        permuted_data2 = combined[len(data1):]
        _, permuted_p_value = perform_ttest(permuted_data1, permuted_data2)
        p_values.append(permuted_p_value)
    return p_values

def analyze_p_values(p_values, original_p_value, alpha=0.05):
    p_values = np.array(p_values)
    less_extreme = p_values <= original_p_value
    p_value_permutation = np.mean(less_extreme)
    return p_value_permutation < alpha

def main():
    data1, data2 = generate_data(30)
    t_stat, original_p_value = perform_ttest(data1, data2)
    p_values = permute_data(data1, data2, 1000)
    result = analyze_p_values(p_values, original_p_value)
    print(result)
main()