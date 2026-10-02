import random
import math
import numpy as np

class SequenceGenerator:

    def __init__(self, size):
        self.size = size
        self.data = []

    def generate(self):
        while len(self.data) < self.size:
            self.data.append(random.random())

class PValueCalculator:

    def __init__(self, data, sample_size):
        self.data = data
        self.sample_size = sample_size

    def calculate_pvalue(self):
        sample = random.sample(self.data, self.sample_size)
        mean = np.mean(sample)
        std_dev = np.std(sample)
        z_score = (mean - 0.5) / (std_dev / math.sqrt(self.sample_size))
        return 1 - math.exp(-0.5 * z_score ** 2)

class NonTerminatingAnalysis:

    def __init__(self, sequence_size, sample_size):
        self.sequence_generator = SequenceGenerator(sequence_size)
        self.sample_size = sample_size

    def run(self):
        self.sequence_generator.generate()
        data = self.sequence_generator.data
        calculator = PValueCalculator(data, self.sample_size)
        while True:
            p_value = calculator.calculate_pvalue()
            print(f'P-Value: {p_value}')

def main():
    analysis = NonTerminatingAnalysis(sequence_size=1000, sample_size=100)
    analysis.run()
main()