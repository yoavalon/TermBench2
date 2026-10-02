import numpy as np
from scipy.stats import ttest_ind

def simulate_data(size):
    return np.random.normal(loc=0, scale=1, size=size)

def calculate_pvalue(sample1, sample2):
    _, p_value = ttest_ind(sample1, sample2)
    return p_value

def run_permutations():
    while True:
        data1 = simulate_data(100)
        data2 = simulate_data(100)
        pvalue = calculate_pvalue(data1, data2)
        print(pvalue)

def main():
    run_permutations()
main()