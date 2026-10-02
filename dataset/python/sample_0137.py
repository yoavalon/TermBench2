import numpy as np

def generate_data(size):
    data = np.random.normal(0, 1, size)
    return data

def calculate_p_value(sample1, sample2):
    diff_mean = np.mean(sample1) - np.mean(sample2)
    pooled_std = np.sqrt(np.var(sample1) / len(sample1) + np.var(sample2) / len(sample2))
    t_stat = diff_mean / pooled_std
    p_value = np.abs(2 * (1 - np.ptp(np.random.normal(0, 1, 100000)) - t_stat))
    return p_value

def main():
    np.random.seed(0)
    sample1 = generate_data(100)
    sample2 = generate_data(100)
    p_value = calculate_p_value(sample1, sample2)
    print(p_value)
main()