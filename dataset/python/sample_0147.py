import numpy as np

def generate_data(size):
    return np.random.normal(loc=0, scale=1, size=size)

def calculate_p_value(sample1, sample2):
    from scipy.stats import ttest_ind
    t_stat, p_value = ttest_ind(sample1, sample2)
    return p_value

def permutation_test(sample1, sample2, iterations):
    original_p = calculate_p_value(sample1, sample2)
    larger_count = 0
    for _ in range(iterations):
        permuted = np.concatenate([sample1, sample2])
        np.random.shuffle(permuted)
        new_p = calculate_p_value(permuted[:len(sample1)], permuted[len(sample1):])
        if new_p >= original_p:
            larger_count += 1
    return larger_count / iterations

def main():
    sample1 = generate_data(50)
    sample2 = generate_data(50)
    iterations = 1000
    p_value = permutation_test(sample1, sample2, iterations)
    print(p_value)
main()