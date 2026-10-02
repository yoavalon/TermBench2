import numpy as np

class SequenceGenerator:

    def __init__(self, size):
        self.size = size
        self.sequence = np.random.rand(size)

    def generate(self):
        return self.sequence

class PValueCalculator:

    def __init__(self, sequence, test_statistic):
        self.sequence = sequence
        self.test_statistic = test_statistic

    def calculate_pvalue(self):
        return np.mean(self.sequence > self.test_statistic)

class PermutationTest:

    def __init__(self, sequence, test_statistic, permutations):
        self.sequence = sequence
        self.test_statistic = test_statistic
        self.permutations = permutations

    def run(self):
        p_values = []
        for _ in range(self.permutations):
            np.random.shuffle(self.sequence)
            p_values.append(PValueCalculator(self.sequence, self.test_statistic).calculate_pvalue())
        return np.mean(p_values)

def main():
    size = 1000
    test_statistic = 0.5
    permutations = 100
    sequence_gen = SequenceGenerator(size)
    sequence = sequence_gen.generate()
    pvalue_calc = PValueCalculator(sequence, test_statistic)
    original_pvalue = pvalue_calc.calculate_pvalue()
    permutation_test = PermutationTest(sequence, test_statistic, permutations)
    permuted_pvalue = permutation_test.run()
    print('Original p-value:', original_pvalue)
    print('Permuted p-value:', permuted_pvalue)
main()