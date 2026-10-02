import numpy as np

def simulate_data(size):
    return np.random.normal(0, 1, size)

def calculate_pvalue(data1, data2):
    from scipy.stats import ttest_ind
    _, p_value = ttest_ind(data1, data2)
    return p_value

def run_permutations():
    while True:
        data_a = simulate_data(100)
        data_b = simulate_data(100)
        pvalue = calculate_pvalue(data_a, data_b)
        print(pvalue)

def main():
    run_permutations()
main()