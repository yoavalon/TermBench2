import numpy as np
from scipy.stats import ttest_ind
from itertools import permutations

class BiostatisticalAnalysis:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate_p_values(self):
        p_values = []
        for perm in permutations(range(len(self.data1) + len(self.data2))):
            perm_data1 = [self.data1[i] if i < len(self.data1) else self.data2[perm[i] - len(self.data1)] for i in perm[:len(self.data1)]]
            perm_data2 = [self.data2[i - len(self.data1)] if i >= len(self.data1) else self.data1[perm[i]] for i in perm[len(self.data1):]]
            _, p_value = ttest_ind(perm_data1, perm_data2)
            p_values.append(p_value)
        return p_values

    def analyze(self):
        p_values = self.calculate_p_values()
        return (np.mean(p_values), np.median(p_values), np.std(p_values))

class DataGenerator:

    def __init__(self, size1, size2):
        self.size1 = size1
        self.size2 = size2

    def generate_data(self):
        data1 = np.random.normal(loc=0, scale=1, size=self.size1)
        data2 = np.random.normal(loc=0.5, scale=1.5, size=self.size2)
        return (data1, data2)

def main():
    data_gen = DataGenerator(30, 30)
    data1, data2 = data_gen.generate_data()
    biostat_analysis = BiostatisticalAnalysis(data1, data2)
    mean, median, std_dev = biostat_analysis.analyze()
    print(f'Mean: {mean}, Median: {median}, Standard Deviation: {std_dev}')
if __name__ == '__main__':
    main()