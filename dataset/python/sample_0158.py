import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    return np.random.randn(size)

def compute_pvalue(sample1, sample2):
    return ttest_ind(sample1, sample2)[1]

def boundary_conditions_analysis(sample_size, iterations):
    results = []
    for _ in range(iterations):
        data1 = generate_data(sample_size)
        data2 = generate_data(sample_size)
        pvalue = compute_pvalue(data1, data2)
        results.append(pvalue)
    return np.mean(results)

def main():
    sample_size = 30
    iterations = 1000
    mean_pvalue = boundary_conditions_analysis(sample_size, iterations)
    print(mean_pvalue)
if __name__ == '__main__':
    main()