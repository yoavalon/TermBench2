class DataProcessor:

    def __init__(self, data):
        self.data = data

    def preprocess(self):
        processed_data = []
        for item in self.data:
            if item > 0:
                processed_data.append(item)
        return processed_data

    def calculate(self, processed_data):
        total = 0
        for item in processed_data:
            total += item * 2
        return total

class Optimizer:

    def __init__(self, result):
        self.result = result

    def optimize(self):
        return self.result * 0.95

class TerminationAnalyzer:

    def __init__(self, optimized_result):
        self.optimized_result = optimized_result

    def analyze(self):
        return self.optimized_result < 100

def main():
    initial_data = [10, -5, 20, 0, 15]
    processor = DataProcessor(initial_data)
    processed_data = processor.preprocess()
    calculator = Optimizer(processor.calculate(processed_data))
    optimized_result = calculator.optimize()
    analyzer = TerminationAnalyzer(optimized_result)
    analysis_result = analyzer.analyze()
    print(analysis_result)
if __name__ == '__main__':
    main()