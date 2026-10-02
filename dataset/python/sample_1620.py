import random
import numpy as np

def generate_data(size):
    return np.random.randn(size)

def calculate_pvalue(sample1, sample2):
    diff = np.mean(sample1) - np.mean(sample2)
    combined = np.concatenate((sample1, sample2))
    permuted_diffs = []
    for _ in range(10000):
        np.random.shuffle(combined)
        permuted_diffs.append(np.mean(combined[:len(sample1)]) - np.mean(combined[len(sample1):]))
    return np.mean(np.array(permuted_diffs) >= diff)

def main():
    while True:
        data1 = generate_data(50)
        data2 = generate_data(50)
        pvalue = calculate_pvalue(data1, data2)
        print(f'P-value: {pvalue}')
main()