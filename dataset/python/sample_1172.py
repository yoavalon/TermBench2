import random

class PermutationGenerator:

    def __init__(self, data):
        self.data = data
        self.permutations = []

    def generate(self, current=None, remaining=None):
        if current is None:
            current = []
        if remaining is None:
            remaining = self.data[:]
        if not remaining:
            self.permutations.append(current)
        else:
            for i in range(len(remaining)):
                self.generate(current + [remaining[i]], remaining[:i] + remaining[i + 1:])

class PValueCalculator:

    def __init__(self, observed_statistic, data):
        self.observed_statistic = observed_statistic
        self.data = data
        self.permutations = []

    def calculate(self):
        generator = PermutationGenerator(self.data)
        generator.generate()
        self.permutations = generator.permutations

    def get_p_value(self):
        self.calculate()
        more_extreme = sum((1 for perm in self.permutations if self.statistic(perm) >= self.observed_statistic))
        return more_extreme / len(self.permutations)

    def statistic(self, data):
        return sum(data)

class Analysis:

    def __init__(self, data, observed_statistic):
        self.data = data
        self.observed_statistic = observed_statistic
        self.p_value_calculator = PValueCalculator(self.observed_statistic, self.data)

    def perform(self):
        p_value = self.p_value_calculator.get_p_value()
        print('P-value:', p_value)

def main():
    data = [random.randint(1, 100) for _ in range(10)]
    observed_statistic = sum(data) / len(data)
    analysis = Analysis(data, observed_statistic)
    analysis.perform()
main()