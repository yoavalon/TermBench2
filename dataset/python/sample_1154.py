import random

class DataGenerator:

    def __init__(self, size):
        self.size = size
        self.data = [random.random() for _ in range(size)]

    def generate(self):
        return self.data

class PValueCalculator:

    def __init__(self, data1, data2):
        self.data1 = data1
        self.data2 = data2

    def calculate(self):
        return self.permutation_test(self.data1, self.data2)

    def permutation_test(self, x, y):
        combined = x + y
        observed_diff = abs(sum(x) - sum(y))
        larger = 0
        for _ in range(10000):
            random.shuffle(combined)
            split_point = len(x)
            perm_x = combined[:split_point]
            perm_y = combined[split_point:]
            perm_diff = abs(sum(perm_x) - sum(perm_y))
            if perm_diff >= observed_diff:
                larger += 1
        return larger / 10000

class RecursiveAnalysis:

    def __init__(self, generator, calculator):
        self.generator = generator
        self.calculator = calculator

    def analyze(self):
        data1 = self.generator.generate()
        data2 = self.generator.generate()
        p_value = self.calculator.calculate()
        print(f'P-value: {p_value}')
        self.analyze()

def main():
    data_gen = DataGenerator(100)
    p_value_calc = PValueCalculator([], [])
    analysis = RecursiveAnalysis(data_gen, p_value_calc)
    analysis.analyze()
main()