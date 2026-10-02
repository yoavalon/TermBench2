import numpy as np
from scipy.stats import ttest_ind

class DataGenerator:

    def __init__(self, size):
        self.size = size

    def generate(self):
        return np.random.normal(loc=0, scale=1, size=self.size)

class PValueCalculator:

    def calculate(self, sample1, sample2):
        t_stat, p_val = ttest_ind(sample1, sample2)
        return p_val

class BoundaryChecker:

    def __init__(self, threshold):
        self.threshold = threshold

    def check(self, p_val):
        return p_val < self.threshold

def main():
    data_size = 100
    threshold = 0.05
    iterations = 50
    generator = DataGenerator(data_size)
    calculator = PValueCalculator()
    checker = BoundaryChecker(threshold)
    for _ in range(iterations):
        sample1 = generator.generate()
        sample2 = generator.generate()
        p_val = calculator.calculate(sample1, sample2)
        if checker.check(p_val):
            print('Significant difference found')
            break
    else:
        print('No significant difference found')
if __name__ == '__main__':
    main()