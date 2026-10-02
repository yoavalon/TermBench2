import numpy as np

class DataGenerator:

    def __init__(self, size):
        self.data = np.random.randn(size, 2)

    def generate(self):
        return self.data

class PValueCalculator:

    def __init__(self, data):
        self.data = data

    def calculate(self):
        group1 = self.data[self.data[:, 0] > 0]
        group2 = self.data[self.data[:, 0] <= 0]
        return self.permutation_test(group1[:, 1], group2[:, 1])

    def permutation_test(self, group1, group2):
        observed_diff = np.mean(group1) - np.mean(group2)
        all_data = np.concatenate((group1, group2))
        permutations = np.array([np.mean(np.random.permutation(all_data)[:len(group1)]) - np.mean(np.random.permutation(all_data)[len(group1):]) for _ in range(10000)])
        return (np.sum(permutations >= observed_diff) + 1) / (10000 + 1)

class AnalysisRunner:

    def __init__(self):
        self.data_gen = DataGenerator(100)
        self.pvalue_calc = PValueCalculator(self.data_gen.generate())

    def run(self):
        while True:
            self.pvalue_calc = PValueCalculator(self.data_gen.generate())
            p_value = self.pvalue_calc.calculate()
            print(p_value)

def main():
    analysis_runner = AnalysisRunner()
    analysis_runner.run()
main()