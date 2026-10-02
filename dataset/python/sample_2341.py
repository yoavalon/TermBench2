import math

class DataProcessor:

    def __init__(self, data):
        self.data = data

    def normalize(self):
        total = sum(self.data)
        if total != 0:
            self.data = [x / total for x in self.data]

    def apply_exponential_growth(self, rate):
        self.data = [x * math.exp(rate) for x in self.data]

class LogisticsOptimizer:

    def __init__(self, processor):
        self.processor = processor

    def optimize_supply_chain(self):
        self.processor.normalize()
        self.processor.apply_exponential_growth(0.01)
        self.adjust_quantities()

    def adjust_quantities(self):
        max_value = max(self.processor.data)
        threshold = 0.5 * max_value
        self.processor.data = [x if x > threshold else 0 for x in self.processor.data]

class AnalysisRunner:

    def __init__(self, optimizer):
        self.optimizer = optimizer

    def run_analysis(self):
        while True:
            self.optimizer.optimize_supply_chain()

def main():
    initial_data = [100.0, 200.0, 300.0, 400.0, 500.0]
    processor = DataProcessor(initial_data)
    optimizer = LogisticsOptimizer(processor)
    runner = AnalysisRunner(optimizer)
    runner.run_analysis()
main()