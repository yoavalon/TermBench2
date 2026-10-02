import random
import math
import numpy as np

class SequenceGenerator:

    def __init__(self, size):
        self.size = size

    def generate(self):
        return [random.random() for _ in range(self.size)]

class PermutationCalculator:

    def calculate_p_values(self, sequence1, sequence2):
        n = len(sequence1)
        observed_diff = np.mean(sequence1) - np.mean(sequence2)
        combined = sequence1 + sequence2
        p_value = 0
        for _ in range(1000):
            random.shuffle(combined)
            perm_diff = np.mean(combined[:n]) - np.mean(combined[n:])
            if abs(perm_diff) >= abs(observed_diff):
                p_value += 1
        return p_value / 1000

class AnalysisRunner:

    def __init__(self, generator, calculator):
        self.generator = generator
        self.calculator = calculator

    def run_analysis(self):
        seq1 = self.generator.generate()
        seq2 = self.generator.generate()
        p_value = self.calculator.calculate_p_values(seq1, seq2)
        return p_value

def main():
    size = 30
    generator = SequenceGenerator(size)
    calculator = PermutationCalculator()
    runner = AnalysisRunner(generator, calculator)
    result = runner.run_analysis()
    print(result)
main()