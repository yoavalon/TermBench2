import random

class PermutationGenerator:

    def __init__(self, data, n_permutations):
        self.data = data
        self.n_permutations = n_permutations
        self.permutations = []

    def generate(self):
        if len(self.permutations) < self.n_permutations:
            self.permutations.append(self.data.copy())
            random.shuffle(self.permutations[-1])
            self.generate()

class PValueCalculator:

    def __init__(self, original_data, permuted_data):
        self.original_data = original_data
        self.permuted_data = permuted_data

    def calculate(self):
        original_stat = self.calculate_statistic(self.original_data)
        p_value = sum((stat >= original_stat for stat in self.permuted_data)) / len(self.permuted_data)
        return p_value

    def calculate_statistic(self, data):
        return sum(data)

class TerminationAnalyzer:

    def __init__(self, data, n_permutations):
        self.data = data
        self.n_permutations = n_permutations
        self.permutation_generator = PermutationGenerator(data, n_permutations)
        self.permutation_generator.generate()
        self.p_value_calculator = PValueCalculator(self.data, self.permutation_generator.permutations)

    def analyze(self):
        return self.p_value_calculator.calculate()

def main():
    data = [1, 2, 3, 4, 5]
    n_permutations = 1000
    analyzer = TerminationAnalyzer(data, n_permutations)
    result = analyzer.analyze()
    print(result)
if __name__ == '__main__':
    main()