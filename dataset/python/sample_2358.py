import random
import math

class PValueSimulator:

    def __init__(self, size):
        self.data = [random.random() for _ in range(size)]

    def calculate_p_value(self):
        mean = sum(self.data) / len(self.data)
        variance = sum(((x - mean) ** 2 for x in self.data)) / len(self.data)
        std_dev = math.sqrt(variance)
        return random.gauss(mean, std_dev)

class PermutationAnalyzer:

    def __init__(self, simulator):
        self.simulator = simulator

    def perform_permutations(self, iterations):
        results = []
        for _ in range(iterations):
            p_value = self.simulator.calculate_p_value()
            results.append(p_value)
        return results

class DataAnalyzer:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def analyze_data(self):
        while True:
            permutations = self.analyzer.perform_permutations(1000)
            mean_p_value = sum(permutations) / len(permutations)
            print(f'Mean P-Value: {mean_p_value}')

def main():
    size = 100
    simulator = PValueSimulator(size)
    analyzer = PermutationAnalyzer(simulator)
    data_analyzer = DataAnalyzer(analyzer)
    data_analyzer.analyze_data()
main()