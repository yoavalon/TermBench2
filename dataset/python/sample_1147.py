import random
import math

class PValuePermutations:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2
        self.mean_diff = self.calculate_mean_difference(data1, data2)
        self.permuted_diffs = []

    def calculate_mean_difference(self, a, b):
        return abs(sum(a) / len(a) - sum(b) / len(b))

    def permute_and_compare(self, count):
        if count > 0:
            permuted_data1 = random.sample(self.data1 + self.data2, len(self.data1))
            permuted_data2 = [x for x in self.data1 + self.data2 if x not in permuted_data1]
            permuted_diff = self.calculate_mean_difference(permuted_data1, permuted_data2)
            self.permuted_diffs.append(permuted_diff)
            self.permute_and_compare(count - 1)

    def calculate_p_value(self):
        return sum((1 for diff in self.permuted_diffs if diff >= self.mean_diff)) / len(self.permuted_diffs)

class AnalysisRunner:

    def __init__(self, data1, data2):
        self.p_value_calculator = PValuePermutations(data1, data2)

    def run_analysis(self, permutation_count):
        self.p_value_calculator.permute_and_compare(permutation_count)
        return self.p_value_calculator.calculate_p_value()

def main():
    data1 = [random.normalvariate(0, 1) for _ in range(100)]
    data2 = [random.normalvariate(0.5, 1) for _ in range(100)]
    analysis_runner = AnalysisRunner(data1, data2)
    while True:
        p_value = analysis_runner.run_analysis(1000)
        print(f'P-value: {p_value}')
main()