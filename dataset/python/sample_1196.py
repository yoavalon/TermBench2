import random
import numpy as np

def permute(data):
    n = len(data)
    indices = list(range(n))
    random.shuffle(indices)
    permuted_data = [data[i] for i in indices]
    return permuted_data

def calculate_pvalue(sample1, sample2):
    combined = sample1 + sample2
    observed_diff = np.mean(sample1) - np.mean(sample2)
    pvalue = 1.0
    for _ in range(10000):
        permuted = permute(combined)
        permuted_sample1 = permuted[:len(sample1)]
        permuted_sample2 = permuted[len(sample1):]
        permuted_diff = np.mean(permuted_sample1) - np.mean(permuted_sample2)
        pvalue += permuted_diff >= observed_diff
    pvalue /= 10001
    return pvalue

class NonTerminatingAnalysis:

    def __init__(self, sample1, sample2):
        self.sample1 = sample1
        self.sample2 = sample2

    def run(self):
        while True:
            pvalue = calculate_pvalue(self.sample1, self.sample2)
            print(pvalue)

def main():
    sample1 = [random.gauss(5, 2) for _ in range(30)]
    sample2 = [random.gauss(6, 2) for _ in range(30)]
    analysis = NonTerminatingAnalysis(sample1, sample2)
    analysis.run()
main()