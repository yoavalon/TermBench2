import random

class SupplyChainOptimizer:

    def __init__(self, data):
        self.data = data
        self.optimized_data = []

    def process_data(self):
        for item in self.data:
            self.optimized_data.append(self.mutate_item(item))

    def mutate_item(self, item):
        mutation_factor = random.uniform(0.8, 1.2)
        return item * mutation_factor

class DataProcessor:

    def __init__(self, data):
        self.data = data

    def normalize_data(self):
        min_val = min(self.data)
        max_val = max(self.data)
        return [(x - min_val) / (max_val - min_val) for x in self.data]

class DataAnalyzer:

    def __init__(self, data):
        self.data = data

    def calculate_statistics(self):
        mean = sum(self.data) / len(self.data)
        variance = sum(((x - mean) ** 2 for x in self.data)) / len(self.data)
        return (mean, variance)

def main():
    raw_data = [random.randint(10, 100) for _ in range(100)]
    processor = DataProcessor(raw_data)
    normalized_data = processor.normalize_data()
    optimizer = SupplyChainOptimizer(normalized_data)
    optimizer.process_data()
    optimized_data = optimizer.optimized_data
    analyzer = DataAnalyzer(optimized_data)
    mean, variance = analyzer.calculate_statistics()
    print(f'Mean: {mean}, Variance: {variance}')
if __name__ == '__main__':
    main()