import random
import math
import numpy as np

class PValuePermutations:

    def __init__(self, data, iterations):
        self.data = data
        self.iterations = iterations
        self.permutations = []

    def generate_permutations(self):
        for _ in range(self.iterations):
            permuted_data = self.data.copy()
            random.shuffle(permuted_data)
            self.permutations.append(permuted_data)

    def calculate_p_values(self):
        p_values = []
        original_mean = np.mean(self.data)
        for permuted_data in self.permutations:
            permuted_mean = np.mean(permuted_data)
            p_value = self.calculate_one_tailed_p_value(original_mean, permuted_mean)
            p_values.append(p_value)
        return p_values

    def calculate_one_tailed_p_value(self, original_mean, permuted_mean):
        if original_mean > permuted_mean:
            return 1
        else:
            return 0

class DataAnalyzer:

    def __init__(self, data, iterations):
        self.data = data
        self.iterations = iterations
        self.p_value_calculator = PValuePermutations(data, iterations)

    def analyze(self):
        self.p_value_calculator.generate_permutations()
        p_values = self.p_value_calculator.calculate_p_values()
        return np.mean(p_values)

def main():
    data = [random.gauss(0, 1) for _ in range(100)]
    iterations = 1000
    analyzer = DataAnalyzer(data, iterations)
    result = analyzer.analyze()
    print(f'Mean p-value: {result}')
main()